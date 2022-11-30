#include <bits/stdc++.h>
using namespace std;

int N, T;
string s;


void solve(){
    cin >> N;
    cin >> s;
    
    long long zeros = 0LL;
    long long ones = 0LL;
    int bestZStreak = 0;
    int bestOStreak = 0;
    
    for(int i = 0; i < N; i ++){
        if(s[i] == '0'){
            zeros ++;
        }else{
            ones ++;
        }
    }

    long long ans = zeros * ones;
    int last = -1;
    int streak = 0;
    for(int i = 0; i < N; i ++){
        int charint = s[i] - '0';
        if(charint != last){
            streak = 1;
            last = charint;
        }else{
            streak ++;
        }
        if(charint == 1){
            bestOStreak = max(bestOStreak, streak);
        }else{
            bestZStreak = max(bestZStreak, streak);
        }
    }
    long long bestZLL = bestZStreak;
    long long bestOLL = bestOStreak;
    // cout << "Alt answers " << bestZLL << "^2 or " << bestOLL << "^2 " << endl;
    ans = max(ans, bestZLL * bestZLL);
    ans = max(ans, bestOLL * bestOLL);
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    while(T --) solve();
    return 0;
}
