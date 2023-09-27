#include <bits/stdc++.h>
#define MAXN 200001 
using namespace std;

int N;

pair<int,int> arr[MAXN];
long long ans[MAXN];

void solve(){
    cin >> N;   
    for(int i = 0; i < N; i ++){
        cin >> arr[i].first;
        arr[i].second = i; // orig idx
    }
    sort(arr, arr + N);
    long long left = 0;
    long long right = 0;
    
    for(int i = 1; i < N; i ++){
        right += arr[i].first - arr[0].first;
    }

    for(int i = 0; i < N; i ++){
        // to the right positions = i
        if(i > 0) left += ((long long) (i + 1)) * ((long long) (arr[i].first - arr[i - 1].first));
        // to the left positions N - 1 - i 
        // cout << arr[i].second << " is " << right << " + " << left << " + " << N << " = " << (right + left + N) << endl;
        ans[arr[i].second] = right + left + ((long long) N); // apparently ranges are inclusive so add N
        // calculate the next
        if(i < (N - 1)) right -= ((long long) (N - i)) * ((long long) (arr[i + 1].first - arr[i].first));
    }

    for(int i = 0; i < N; i ++){
        cout << ans[i] << " ";
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