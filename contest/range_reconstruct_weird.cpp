#include <bits/stdc++.h>
#define MAXN 301
using namespace std;

int N;
int output[MAXN] = {0};
int input[MAXN][MAXN];

void solve(){
    int newRange, record;
    cin >> N;
    fill(output, output + N, 0);
    for(int i = 0; i < N; i ++){
        for(int j = i; j < N; j ++){
            cin >> input[i][j];
        }
    }
    for(int k = 1; k < N; k ++){
        // record = 0;
        for(int i = 0; (i + k) < N; i ++){
            newRange = input[i][i + k];
            // cout << i << "," << j << " read " << newRange << endl;
            if(k > 0 && newRange != input[i][i + k - 1]){  //record){
                // New record therefore we must have new high
                // cout << "[" << j << "]" << " = [" << i << "] + " << newRange << endl;
                output[i + k] = output[i] + newRange;
                record = newRange;
            }
        }
    }
    for(int i = 0; i < N; i ++){
        cout << (output[i]) << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
