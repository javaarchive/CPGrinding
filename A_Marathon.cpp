#include <bits/stdc++.h>

using namespace std;
void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << ( ((int) (a < b) + (int) (a < c) + (int) (a < d)));
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --){
        solve();
    }
    return 0;
}
