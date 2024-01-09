#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;

map<long long,long long> invAns;
long long arr[MAXN] = {0};
long long ps[MAXN] = {0};
long long orig[MAXN] = {0};

void solve(){
    int N;
    cin >> N;
    invAns.clear();
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
        orig[i] = arr[i];
    }
    sort(arr, arr + N);
    fill(ps, ps + N + 1, 0);
    long long sum = 0;
    for(int i = 0; i < N; i ++){
        ps[i + 1] = ps[i] + arr[i];
    }
    for(int i = N - 1; i >= 0; i --){
        long long maxAddableScore = ps[i];
        long long scoreAfterAdds = maxAddableScore + arr[i];
        long long removes = i;
        long long ans = removes; 
        if(i != N - 1 && scoreAfterAdds >= arr[i + 1]){
            ans = max(ans, invAns[arr[i + 1]]);
        }
        invAns[arr[i]] = max(invAns[arr[i]], ans);
    }
    for(int i = 0; i < N; i ++){
        cout << invAns[orig[i]] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}