#include <bits/stdc++.h>
#define MAXN 200005

using namespace std;

int N;
int arr[MAXN];

void solve(){
    set<int> satsifying;
    vector<int> satsifying_vec;
    map<int,int> invIndex;
    
    cin >> N;
    int sPos = 0;
    for(int i = 0; i < N; i ++){
        int x;
        cin >> x;
        arr[i] = x;
        if(x < (i + 1)){
            // cout << i << " satsifies " << arr[i] << endl;
            satsifying_vec.push_back(i);
            satsifying.insert(i + 1);
            invIndex[i + 1] = sPos;
            sPos ++;
        }
    }

    long long ans = 0;

    // index = j
    for(int index: satsifying_vec){
        // cout << "== " << index << endl;
        // find lower
        auto iter = satsifying.upper_bound(arr[index]);
        int indexBelow = *iter;
        while(*iter >= (arr[index]) && iter != satsifying.begin()){
            // cout << " at " << *iter << endl;
            iter --;
        }
        if(iter == satsifying.begin() && *iter >= (arr[index])){
            // cout << "Iterated to start of set val " << *iter << " looking for lower than " << arr[index] << " index " << index << endl; 
            continue;
        }
        indexBelow = *iter;
        int satsifying = invIndex[indexBelow] + 1;
        ans += satsifying;
    }

    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --) solve();
    return 0;
}
