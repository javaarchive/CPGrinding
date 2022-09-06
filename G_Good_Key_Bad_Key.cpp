#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int N, K;

long long arr[MAXN];

void solve(){
    cin >> N >> K;
    long long ans = 0;

    for(int i = 0; i < N; i ++){
        cin >> arr[i];
        ans += arr[i] - K; // initial all good key case
    }

    for(int i = 0; i < N; i ++){
        long long possible_ans = 0;
        // cout << "i: " << i << " so ";
        for(int j = 0; j < i; j ++){
            // good key calc
            // cout << arr[j] << "-" << K << " ";
            possible_ans += arr[j] - K;
        }
        for(int j = i; j < N; j ++){
            if((j - i) > 35){
                break; // don't even bother they'll all be worthless
            }
            int divs = j - i + 1; // how many times we divide
            int toAdd = arr[j];
            while(divs --){
                toAdd = toAdd/2;
            }
            possible_ans += toAdd;
        }
        ans = max(ans, possible_ans);
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