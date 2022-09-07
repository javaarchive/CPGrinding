#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    int R = 0, L = 0;
    string line;
    cin >> line;
    for(int i = 0; i < N; i ++){
        if(line[i] == 'R'){
            R ++;
        }else{
            L ++;
        }
    }
    // long long lowest = min(R,L);
    // long long highest = max(R,L);
    // long long largest = -1;
    // cout << "LOWEST " << lowest << " HIGHEST " << highest << endl;
    for(int k = 1; k <= N; k ++){
        // cout << "K = " << k << endl;
        long long ans = 0;
        if(k <= lowest){
            // (lowest - k) * (highest + k);
            long long newLowest = lowest - k;
            long long newHighest = highest + k;

            // cout << "new low: " << newLowest << " and new high: " << newHighest << endl; 

            long long lValue = (newLowest * (newLowest + 1))/2;
            long long rValue = (newHighest * (newHighest + 1))/2;

            cout << lValue << " and " << rValue << endl;

            ans = lValue + rValue;

            largest = max(largest,ans);
        }else{
            ans = largest;
        }
        cout << "^" << ans; 
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --) solve();
}