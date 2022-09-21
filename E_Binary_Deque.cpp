#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;

int arr[MAXN];
int N, S;

void solve(){
    cin >> N >> S;
    
    for(int i = 0; i < N; i ++){
        cin >> arr[i];    
    }
    // Two pointers / Sliding window
    int sum = 0;
    int ending = 0;
    int best = INT32_MAX;
    for(int start = 0; start < N; start ++){
        if(start > 0){
            /*if(arr[start - 1] > 0){
                cout << "- " << arr[start - 1] << endl;
            }*/
            sum -= arr[start - 1];
        }
        ending = max(ending, start);
        bool looped = false;
        for(; ending < N; ending ++){
            if(sum == S && arr[ending] != 0){
                break;
            }
            looped = true;
            // cout << "+ arr[" << ending << "] = " << arr[ending] << endl; 
            sum += arr[ending];
        }
        // if(looped) ending --; // last good
        // cout << start << " < --- > " << ending-1 << " sum: " << sum << endl;
        if(sum != S){
            // not enough
            break;
        }
        // sum == S
        int cost = start + N - 1 - (ending-1) ;
        // cout << "Final cost " << cost << endl;
        best = min(best, cost);
    }
    // cout << "ANS: ";
    cout << (best == INT32_MAX ? -1 : best) << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --) solve();
    return 0;
}
