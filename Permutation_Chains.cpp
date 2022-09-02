#include <bits/stdc++.h>
#define MAXN 101
#define MAXNN 101

using namespace std;

int arr[MAXN] = {0};

void solve(){
    int N;
    cin >> N;
    // Populate
    for(int i = 0; i < N; i ++){
        arr[i] = i + 1;
    }
    int chain = 0;
    if(N == 1){
        cout << "1" << endl;
        cout << "1" << endl;
        return;
    }
    cout << N << endl; // lol we can predict length
    
    // initial
    for(int i = 0; i < N; i ++) cout << arr[i] << " ";
    cout << endl;
    if(N < 2){
        return; // sanity
    }
    swap(arr[0], arr[N - 1]);
    for(int i = 0; i < N; i ++) cout << arr[i] << " ";
    cout << endl;
    for(int i = N - 2; i >= 1; i --){
        swap(arr[i],arr[i + 1]);
        for(int i = 0; i < N; i ++) cout << arr[i] << " ";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN--) solve();
    return 0;
}
