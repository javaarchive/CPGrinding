#include <bits/stdc++.h>
using namespace std;

int T;

int calc(string s){
    if(s[0] == 'M'){
        return 0;
    }else if(s[s.size() - 1] == 'S'){
        return -1 * (s.size());
    }else{
        return s.size();
    }
}

void solve(){
    string a,b;
    cin >> a >> b;
    int as = calc(a), bs = calc(b);
    if(as == bs){
        cout << "=" << endl;
    }else if(as < bs){
        cout << "<" << endl;
    }else{
        cout << ">" << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin >> T;
    while(T --){
        solve();
    }    
    return 0;
}
