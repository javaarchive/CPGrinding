#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001



int A[MAXN];
int B[MAXN];

int N;

int fastQuickPow2(int p){
    return 1 << p;
}

void solve(){
    cin >> N;
    int mod = N % 4;
    bool printExtra = false;
    if(mod == 0){
        // TODO
        // Inverses of each other
        // 000000001
        // 111111111 (flip all)
        // --------- XOR
        // 111111110
        int maxDigits = fastQuickPow2(N) + 3;
        int allOnes = fastQuickPow2(maxDigits + 1) - 1;
        for(int i = 1; i <= N/2; i ++){
            A[i - 1] = i;
            B[i - 1] = allOnes - i;
        }
    }else if(mod == 1){
        // TODO
        // Inverses of each other
        // 000000001
        // 111111111 (flip all)
        // --------- XOR
        // 111111110
        int maxDigits = fastQuickPow2(N) + 3;
        int allOnes = fastQuickPow2(maxDigits + 1) - 1;
        for(int i = 1; i <= N/2; i ++){
            A[i - 1] = i;
            B[i - 1] = allOnes - i;
        }
        printExtra = true;
        A[N/2] = 0; // print extra
    }else if(mod == 2){

    }else if(mod == 3){

    }
    // Print it out
    for(int i = 0; i < N/2; i ++){
        cout << A[i] << " ";
        cout << B[i] << " ";
    }
    if(printExtra){
        cout << A[N/2];
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --){
        solve();
    }
    return 0;
}
