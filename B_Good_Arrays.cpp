#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int N;
long long arr[MAXN];
long long b[MAXN];

long long sum;

void solve(){
    cin >> N;
    sum = 0;

    for(int i = 0; i < N; i ++){
        cin >> arr[i];
        sum += arr[i];
    }


    // simple case
    if(N == 1){
        cout << "NO" << endl;
        return;
    }
    
    for(int i = 0; i < N; i ++){
        if(i == N - 1){
            b[i] = sum;
            if(b[i] == arr[i]){
                // rebalance operation
                int swapIdx = 0;
                while(b[i] == arr[i] || b[swapIdx] == arr[swapIdx]){
                    b[i] --;
                    b[swapIdx] ++;
                    if(b[i] < 1){
                        // rebalancing fails
                        // cout << "NO" << endl;
                        // return;
                        break;
                    }
                }
                // cout << "Rebal " << b[i] << " " << b[swapIdx] << endl;
            }
        }else if(arr[i] == 1){
            b[i] = 2;
        }else{
            b[i] = 1;
        }
        sum -= b[i];
        if(sum < 0 || b[i] < 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    
    while(T --) solve();

    return 0;
}
