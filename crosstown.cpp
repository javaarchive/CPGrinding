#include <bits/stdc++.h>
using namespace std;
#define MAXNM 11

int entry[MAXNM] = {0};
int exity[MAXNM] = {0};

void solve(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i ++){
        cin >> entry[i];
        entry[i] --;
    }
    for(int i = 0; i < N; i ++){
        cin >> exity[i];
        exity[i] --;
    }
    int ans = 0;
    for(int i = 0; i < N; i ++){
        // cout << exity[i] << " <- " << entry[i] << endl;
        ans = max(ans, (M + exity[i] - entry[i]) % M );
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
