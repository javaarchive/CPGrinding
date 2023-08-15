#include <bits/stdc++.h>
#define MAXN 501
using namespace std;

int arr[MAXN];

void solve(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    int m = 0;
    for(int i = 0; i < N - 1; i ++){
        if(arr[i] > arr[i + 1]) m = max(m, arr[i]);
    }
    cout << m << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
