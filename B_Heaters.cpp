#include <bits/stdc++.h>
#define MAXN 1001
#define debugg 0
using namespace std;

int arr[MAXN];
int N, R;


void solve(){
    cin >> N >> R;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }

    int ans = 0;
    
    int i = 0;

    int bestDist = 2 * (R - 1) + 1;

    // r2
    // X*
    //   *X
    // 0123
    // +3 -> 2 * (R-1) + 1
    int firstLight = -1;
    for(int i = R-1; i >= 0; i --){
        if(arr[i] == 1){
            firstLight = i;
            break;
        }
    }
    if(firstLight < 0){
        // cerr << "CASE 2" << endl;
        cout << -1 << endl;
        return;
    }

    ans ++; // initial light

    if(debugg) cerr << "INIT: " << firstLight << endl;

    for(int i = firstLight; i < N; i ++){
        if(arr[i] == 1){
            if((i + R - 1) >= (N - 1)){
                if(debugg) cerr << "It's the end, we covered everything " << i << N << endl;
                cout << ans << endl;
                return;
            }
            if(debugg) cerr << i << " -> " << (i + bestDist) << endl;
            for(int j = i + bestDist; j > i; j--){
                if(j < N && arr[j] == 1){
                    if(debugg) cerr << "Sel " << j << endl;
                    ans ++;
                    i = j - 1; // ++ will trigger later
                    break;
                }
            }
            // could not find light
            // agh
            if(debugg) cerr << "i: " << i << endl;
        }else{
            if(debugg) cerr << "ANW: " << i << endl;
            // omfg uncovered point, "ain't no way"
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
