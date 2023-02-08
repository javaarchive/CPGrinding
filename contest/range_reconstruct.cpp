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
    for(int i = N - 1; i >= 0; i --){
        record = 0;
        for(int j = i; j < N; j ++){
            newRange = input[i][j];
            // cout << i << "," << j << " read " << newRange << endl;
            if(newRange != record){
                // New record therefore we must have new high
                // cout << "[" << j << "]" << " = [" << i << "] + " << newRange << endl;
                output[j] = output[i] + newRange;
                record = newRange;
            }
        }
    }
    for(int i = 0; i < N; i ++){
        record = 0;
        for(int j = i; j < N; j ++){
            newRange = input[i][j];
            // cout << i << "," << j << " read " << newRange << endl;
            if(newRange != record){
                // New record therefore we must have new high
                // cout << "[" << j << "]" << " = [" << i << "] + " << newRange << endl;
                output[j] = output[i] + newRange;
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
