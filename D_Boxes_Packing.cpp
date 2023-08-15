#include <bits/stdc++.h>
#define MAXNM 200001

using namespace std;

int N, M, K;
int arr[MAXNM];

void solve(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    int ans = 0;
    int boxes = M - 1;
    int curBoxFilledWith = 0;

    for(int i = N - 1; i >= 0; i --){
        // below this we should have boxes
        if((curBoxFilledWith + arr[i]) > K){
            // use new box
            if(boxes <= 0){
                // cerr << "out of boxes " << endl;
                cout << ans << endl;
                return; 
            }
            // cerr << "Box used at " << i << endl;
            boxes --;
            curBoxFilledWith = 0;
            if(arr[i] > K){
                // oversized item
                // cerr << "PRE END " << endl;
                cout << ans << endl;
                return;
            }
        }
        curBoxFilledWith += arr[i];
        // cerr << "Add " << i << " sz " << arr[i] << " bs " << curBoxFilledWith << endl;
        ans += 1;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
