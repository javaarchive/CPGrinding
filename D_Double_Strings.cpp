#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;
string strs[MAXN];
void solve(){
    unordered_set<string> strs_set;
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        string str;
        cin >> str;
        strs_set.insert(str);
        strs[i] = str;
    }
    for(int i = 0; i < N; i ++){
        int len = strs[i].length();
        int ans = 0;
        // cout << "BEGIN: " << strs[i] << endl;
        for(int s = 1; s < len; s ++){
            // split at s
            string a = strs[i].substr(0,s);
            string b = strs[i].substr(s,string::npos);
            // cout << "CHECK " << a << " and " << b << endl;
            // both have
            if(strs_set.find(a) != strs_set.end() && strs_set.find(b) != strs_set.end()){
                ans = 1;
                break;
            }
        }
        cout << ans;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --) solve();
    return 0;
}
