#include <bits/stdc++.h>
#define MAXN 2001
using namespace std;

int N, K;
long long arr[MAXN];
set<long long> nums;


void solve(){
    cin >> N >> K;
    nums.clear();
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    if(K >= 3){
        // reuse a pair twice
        // then subtract the same thing
        // silly antic = 0
        cout << 0 << endl;
        return;
    }

    long long best = __LONG_LONG_MAX__;
    for(int i = 0; i < N; i ++){
        best = min(best, arr[i]);
    }

    if(K == 0){
        cout << best << endl;
        return;
    }
    for(int i = 0; i < N; i ++){
        for(int j = i + 1; j < N; j ++){
            best = min(best, abs(arr[j] - arr[i]));
        }
    }
    if(K == 1){
        cout << best << endl;
        return;
    }
    // K == 2
    for(int i = 0; i < N; i ++){
        nums.insert(arr[i]);
    }
    // I love set
    for(int i = 0; i < N; i ++){
        for(int j = i + 1; j < N; j ++){
            long long diff = abs(arr[j] - arr[i]);
            auto low_iter = nums.lower_bound(diff);
            if(low_iter != nums.end()){
                best = min(best, abs(*low_iter - diff));
            }
            if(low_iter != nums.begin()){
                best = min(best, abs(*(--low_iter) - diff));
            }
            if((++low_iter) != nums.end()){
                best = min(best, abs(*(++low_iter) - diff));
            }
        }
    }
    cout << best << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}