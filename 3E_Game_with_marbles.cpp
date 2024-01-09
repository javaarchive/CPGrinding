#include <bits/stdc++.h>
#define MAXN 200005

using namespace std;

pair<int,int> colors[MAXN];
int N;

void solve(){
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> colors[i].first;
    }
    for(int i = 0; i < N; i ++){
        cin >> colors[i].second;
    }
    sort(colors, colors + N, [] (auto a,auto b){
        return (a.first + a.second) > (b.first + b.second);
    });
    // reverse(colors, colors + N);
    // cout << colors[0].first << " " << colors[0].second << endl;
    long long ans = 0;
    for(int i = 0; i < N; i ++){
        if(i % 2){
            // enemy/bob turn
            ans -= colors[i].second - 1; 
        }else{
            // you/alice turn
            ans += colors[i].first - 1;
        }
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