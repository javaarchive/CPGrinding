#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int N, K;

long long arr[MAXN];
long long discard[MAXN];
long long badkeyed[MAXN];

void solve(){
    cin >> N >> K;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
        badkeyed[i] = floor(arr[i]/2);
        discard[i] = arr[i] - badkeyed[i]; // diff parity possible
    }
    long long ans = 0;
    for(int i = 0; i < N; i ++){
        int badKeyValue = badkeyed[i];
        int goodKeyValue = arr[i] - K;
        ans += max(badKeyValue, goodKeyValue);
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
