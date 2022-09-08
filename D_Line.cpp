#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    string line;
    cin >> line;
    // long long lowest = min(R,L);
    // long long highest = max(R,L);
    // long long largest = -1;
    // cout << "LOWEST " << lowest << " HIGHEST " << highest << endl;
    vector<pair<long long,int>> choices;
    long long ans = 0LL;
    for(int i = 0; i < N; i ++){
        //   +++ index
        const long long RIGHT = ((N - 1) - (i + 1)) + 1;
        const long long LEFT = i;
        if(line[i] == 'R'){
            // right
            pair<long long, int> choice;
            long long diff = LEFT - RIGHT;
            choice.first = diff;
            choice.second = i;
            ans = ans + (long long) RIGHT;
            choices.push_back(choice);
        }else{
            pair<long long, int> choice;
            // left
            long long diff = RIGHT - LEFT;
            choice.first = diff;
            choice.second = i;
            ans = ans + (long long) LEFT;
            choices.push_back(choice);
        }
    }
    sort(choices.begin(),choices.end());
    // highest first
    reverse(choices.begin(),choices.end());

    // cout << "OK" << endl;

    long long best = INT32_MIN;

    // cout << "OUT ";
    // cout << "N " << N << endl;
    // cout << "INIT " << ans << endl;

    for(int k = 0; k < N; k ++){
        // cout << "BEFORE " << k << endl;
        auto p = choices[k];
        best = max(best, ans);
        // cout << "CHANGE " << p.first << endl;
        // cout << "AFTER" << endl;
        // it gets worse from now
        if(p.first < 0){ // keyword at most
            cout << best << " ";
            continue;
        }
        ans = ans + (long long) p.first;
        best = max(best, ans);
        cout << best << " ";
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --) solve();
}