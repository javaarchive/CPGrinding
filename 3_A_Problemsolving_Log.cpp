#include <bits/stdc++.h>
using namespace std;

int N;
string line;

void solve(){
    map<char,int> freq;
    cin >> N;
    cin >> line;
    for(int i = 0; i < N; i ++){
        freq[line[i]] ++;
    }
    int ans = 0;
    for(char c = 'A'; c <= 'Z'; c ++){
        int requirement = ((int) c ) - ((int) 'A') + 1;
        if (freq[c] >= requirement) {
            ans ++;
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