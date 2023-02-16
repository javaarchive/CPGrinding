#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int N, M;
pair<int,int> arr[MAXN];

long long space = 0;

void solve(){
    cin >> N >> M;
    for(int i = 0; i < N; i ++){
        int a,b;
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = a - b; // decrease in size
        space += a; // all songs uncompressed
    }
    sort(arr, arr + N, [](pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    });
    // cout << "MAX DISCOUNT " << arr[0].second << endl;
    int ans = -1;
    if(space <= M){
        cout << 0 << endl;
        return;
    }
    // take a song one at a time
    for(int i = 0; i < N; i ++){
        space -= arr[i].second;
        if(space <= M){
            // fit!
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
