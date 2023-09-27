#include <bits/stdc++.h>
#define MAXN 200001
using namespace std;

int a[MAXN];
int b[MAXN];

void solve(){
    int minDiff = INT32_MAX;
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i ++){
        cin >> b[i];
    }
    for(int i = 0; i < N; i ++){
        minDiff = min(minDiff, b[i] - a[i]);
    }
    int cnt = 0;
    for(int i = 0; i < N; i ++){
        if(minDiff == (b[i] - a[i])){
            cnt ++;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < N; i ++){
        if(minDiff == (b[i] - a[i])){
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}