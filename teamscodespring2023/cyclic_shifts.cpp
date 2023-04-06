#include <bits/stdc++.h>
#define MAXN 200001

using namespace std;

int N, S;
int A[MAXN];
int B[MAXN];

void solve(){
    cin >> N >> S;
    for(int i = 0; i < N; i ++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i ++){
        cin >> B[i];
    }
    long long ans = 0;
    long long origDiffs = 0;
    // no shift bad case
    for(int i = 0; i < N; i ++){
        ans += abs(A[i] - B[i]);
    }
    origDiffs = ans;
    // shift case
    // 0123456
    // abcdefg
    //  ****
    // acdebfg
    // cerr << "Worst case: " << ans << endl;
    long long rolling = 0;
    long long rolling2 = 0;
    for(int i = 0; i < N; i ++){
        if(i > 0){rolling += abs(A[i] - B[i - 1]);}
        rolling2 += abs(A[i] - B[i]);
        if(i >= S){
            rolling -= abs(A[i - S + 1] - B[i - S]);
            rolling2 -= abs(A[i - S] - B[i - S]);
        }
        

        if(i >= (S-1)){
            long long diff = rolling + (origDiffs - rolling2) + abs(B[i] - A[(i - S + 1)]);
            // cerr << "Rolling " << i << ": " << rolling << " + " << (diff - rolling) << " = " << diff << endl;
            ans = min(ans, diff + 1); // shift itself is an op
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
