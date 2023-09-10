#include <bits/stdc++.h>
using namespace std;

set<int> s;
map<int,int> freq;

void solve(){
    // cout << " === " << endl;
    int N;
    cin >> N;
    s.clear();
    freq.clear();
    int combs = (N * (N - 1))/2;
    for(int i = 0; i < combs; i ++){
        int a;
        cin >> a;
        s.insert(a);
        // cout << " add " << a << " to set " << endl;
        freq[a] ++;
    }
    auto iter = s.begin();
    // now everything is sorted in
    for(int i = 0; i < N; i ++){
        int after = N - 1 - i;
        int before = i;
        if(iter == s.end()){
            // we ran out?
            cout << "ASSERTION FAILURE" << endl;
            return;
        }
        while(freq[*iter] < after){
            iter ++;
            if(iter == s.end()){
                // we ran out?
                cout << "ASSERTION FAILURE" << endl;
                return;
            }
            // cout << " advance to: " << *iter << endl;
        }
        freq[*iter] -= after;
        cout << *iter << " ";
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