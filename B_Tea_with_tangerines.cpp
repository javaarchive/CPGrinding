#include <bits/stdc++.h>

using namespace std;

int N;
int arr[101];
int maximum = 0;
int minimum = INT32_MAX;

long long calc(int whole, int part){
    int slightlyLessThanMax = whole/(part*2 - 1);
    int leftover = whole - (slightlyLessThanMax * (part * 2 - 1));
    long long ans = slightlyLessThanMax;
    if(leftover > 0){
        ans ++;
    }
    return ans;
}

long long check(int val){
    long long ans = 0;
    double val2 = val;
    for(int i = 0; i < N; i ++){
        long long add = calc(arr[i], val2);
        // cout << arr[i] << " has " << add << " of " << val2 << endl;
        ans += (add-1);
    }
    return ans;
}

void solve(){
    cin >> N;
    maximum = 0;
    minimum = INT32_MAX;

    for(int i = 0; i < N; i ++){
        cin >> arr[i];
        maximum = max(maximum, arr[i]);
        minimum = min(minimum, arr[i]);
    }
    
    long long ans = __LONG_LONG_MAX__;
    /*for(int i = minimum; i >= 1; i --){
        ans = min(ans, check(i));
        
        // cout << i << " : " << check(i) << endl;
    }*/
    ans = check(minimum);
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --) solve();
    return 0;
}
