#include <bits/stdc++.h>
#define MAXN 101
#define MAXT 1001

using namespace std;

map<int, int> counts;
int arr[MAXN][MAXN];

int N;

vector<int> seen;

int getFirstNotEqualToInCol(int col, int value){
    for(int i = 0; i < N; i ++){
        if(arr[i][col] != value){
            return arr[i][col];
        }
    }
    return -1;
}

void solve(){

    // reset things
    seen.clear();
    counts.clear();

    vector<int> reconstructed;

    int last = -1;
    cin >> N;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N - 1; j ++){
            cin >> arr[i][j];
        }
    }
    // Find most frequent first digit number
    for(int i = 0; i < N; i ++){
        if(counts[arr[i][0]] == 0){
            seen.push_back(arr[i][0]);
        }
        counts[arr[i][0]] ++;
    }
    // idk observation needs to be correct
    // cout << " SEEN SZ " << seen.size() << endl;
    assert(seen.size() == 2);
    int a,b;
    if(counts[seen[0]] > counts[seen[1]]){
        a = seen[0];
        b = seen[1];
    }else{
        a = seen[1];
        b = seen[0];
    }
    reconstructed.push_back(a);
    reconstructed.push_back(b);
    last = b;
    for(int i = 1; i < N - 1; i ++){
        last = getFirstNotEqualToInCol(i, last);
        reconstructed.push_back(last);
    }
    for(int i = 0; i < N; i ++){
        cout << reconstructed[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();    
    return 0;
}
