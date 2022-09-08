#include <bits/stdc++.h>
#define MAXN 101

using namespace std;

bool compare(char a, char b){
    if(a == 'B' && b == 'G'){return true;}
    if(a == 'G' && b == 'B'){return true;}
    return a == b;
}

void solve(){
    int N;
    cin >> N;
    string la;
    string lb;
    cin >> la;
    cin >> lb;

    for(int i = 0; i < N; i ++){
        if(!compare(la[i],lb[i])){
            cout << "NO" << endl;
            return;
        }        
    }
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
