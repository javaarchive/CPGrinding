#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    int nearest3 = floor(N/3)*3;
    // cout << N << " " << nearest3 << " ";
    int ans = 0;
    ans += nearest3/3;
    if(N % 3 == 1){
        // convert 3 to 2+2
        if(nearest3/3 > 0){
            ans += 1;
        }else{
            // +3-2
            ans += 2;
        }
    }else if(N % 3 == 2){
        ans += 1;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --) solve();
    return 0;
}
