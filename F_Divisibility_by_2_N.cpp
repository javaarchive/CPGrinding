#include <bits/stdc++.h>
using namespace std;
#define MAXN 200002

using namespace std;

int NN;
int N;
int arr[MAXN];

int powof2(int num)
{
    return log2(num & (~(num - 1)));
}

vector<int> choices;

void solve(){
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    int curTotalPowOf2 = 0;
    for(int i = 0; i < N; i ++){
        curTotalPowOf2 += powof2(arr[i]);
    }
    choices.clear();
    for(int i = 0; i < N; i ++){
        int value = powof2(i + 1); // indexes start at 1
        // cout << (i + 1) << " value: " << value << endl;
        // cout << "PUSH " << i << endl;
        choices.push_back(value);
    }
    sort(choices.begin(), choices.end());
    int steps = 0;
    // cout << "CUR TOTAL POW OF 2 " << curTotalPowOf2 << " our N " << N << endl;
    if(curTotalPowOf2 >= N){
        cout << steps << endl;
        return;
    }
    // cout << "choices: ";
    // for(int x: choices){cout << x << " ";}
    // cout << endl;
    for(int i = N - 1; i >= 0; i --){
        curTotalPowOf2 += choices[i];
        // cout << "++ " << choices[i] << endl;
        steps ++;
        if(curTotalPowOf2 >= N){
            cout << steps << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

int main(int argc, char const *argv[])
{
    cin >> NN;
    // cout << "2 = " << powof2(4) << endl;
    // cout << "0 = " << powof2(5) << endl;
    // cout << "1 = " << powof2(2) << endl;
    while(NN --){
        solve();
    }
    return 0;
}
