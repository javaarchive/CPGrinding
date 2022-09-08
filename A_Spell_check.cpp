#include <bits/stdc++.h>
#define FAIL cout << "NO" << endl;return;

using namespace std;



void solve(){
    int _; // don't use this
    cin >> _;
    string line;
    vector<char> chars;
    cin >> line;
    for(int i = 0; i < line.length(); i ++){
        chars.push_back(line[i]);
    }
    sort(chars.begin(),chars.end());
    // for(char c: chars){cout << c;}
    // cout << endl;
    if(chars.size() != 5){FAIL}
    if(chars[0] != 'T'){FAIL}
    if(chars[1] != 'i'){FAIL}
    if(chars[2] != 'm'){FAIL}
    if(chars[3] != 'r'){FAIL}
    if(chars[4] != 'u'){FAIL}
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
