#include <bits/stdc++.h>
using namespace std;

void solve(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i ++)   {
        int N;
        cin >> N;
        int sum = 0;
        for(int j = 0; j < N; j ++){
            int a;
            cin >> a;
            sum += a;
        }
        cout << ((sum % 2) ? "NO":"YES") << endl;
    } 
}

int main(){
    solve();
}