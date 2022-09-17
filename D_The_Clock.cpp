#include <bits/stdc++.h>

using namespace std;

pair<int,int> initTimePair;
pair<int,int> cur;

string a,b;

pair<int,int> parse(string initTime){
    int digit1 = initTime[0] - '0';
    int digit2 = initTime[1] - '0';
    int digit3 = initTime[3] - '0';
    int digit4 = initTime[4] - '0';
    return make_pair(digit1 * 10 + digit2, digit3 * 10 + digit4);
}

bool isPal(){
    int digit1 = floor(cur.first / 10);
    int digit2 = cur.first % 10;
    int digit3 = floor(cur.second / 10);
    int digit4 = cur.second % 10;
    
    return (digit1 == digit4) && (digit2 == digit3);
}

void advanceTime(int minutes){
    cur.second += minutes;
    int hours = floor(cur.second / 60); //extra floor yes
    cur.second = cur.second % 60;
    cur.first += hours;
    cur.first = cur.first % 24;
}

void solve(){
    string initTime;
    int mins;
    cin >> initTime >> mins;
    
    initTimePair = parse(initTime);
    cur = parse(initTime);    

    int ans = 0;

    for(int i = 0; i < 1442; i ++){
        if(initTimePair == cur && i != 0){
            break; // stop counting
        }
        // cout << cur.first << ":" << cur.second << endl;
        if(isPal()){
            ans ++;
        }
        advanceTime(mins);
    }
    
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}