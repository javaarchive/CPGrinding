#include <bits/stdc++.h>
using namespace std;

string s;
int N;

void solve(){
    cin >> s;
    N = s.length();
    int reportedDisappearance = N - 1;
    for(int i = N - 1; i >= 0; i --){
        if(s[i] == '0'){
            reportedDisappearance = i;
        }
    }

    int lastExistence = 0;

    for(int i = 0; i < N; i ++){
        if(s[i] == '1'){
            lastExistence = i;
        }
    }

    cout << (reportedDisappearance - lastExistence + 1) << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}