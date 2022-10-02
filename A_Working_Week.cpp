#include <bits/stdc++.h>

using namespace std;

double N;
int N2;
int slowSolve(){
    int ans = INT32_MIN;
    // these are one indexed btw
    for(int i = 2; i < N2 - 1; i ++){
        for(int j = i + 2; j < N2 - 1; j ++){
            // int evaled = min(i - 1,min(j - i - 1, N2 - j - 1));
            // cout << i << " -> " << j << " = min(" << (i - 1) << "," << (j - i - 1) << "," << N2 - j - 1 << ") = " << evaled << endl; 
            // int evaled = min(abs(j - i), min(abs(N2 - j), abs(N2 - i)));
            // cout << i << " -> " << j << " -> " << N2 << " = " << evaled << endl;
            int a = i - 1;
            int b = j - i - 1;
            int c = N2 - j - 1;
            int evaled = min(abs(b - a), min(abs(c - b), abs(c - a)));
            ans = max(ans,evaled);
        }
    }
    // cout << ans << endl;
    return ans;
}

void solve(){
    cin >> N2;
    N = N2;
    // N but we cannot place on
    // N (given)
    // N - 1 (adjancent to N)
    // 1 (adjacent to N)

    if(N < 100){
        cout << slowSolve() << endl;
        return;
    }
    cout << floor((N-6)/3) << endl;
}

void stress(){
    for(int i = 6; i <= 100; i ++){
        N = i;
        N2 = i;
        int approx = floor((N-6)/3);
        int accurate = slowSolve();
        if(accurate != approx){
            cout << "ERROR ON N " << i << " -> " << accurate << " but got " << approx << endl;
        }
        if(i % 100 == 0){
            // cout << "ELAPSED " << i << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    stress();
    int NN;
    cin >> NN;
    while(NN --) solve();
    
    return 0;
}
