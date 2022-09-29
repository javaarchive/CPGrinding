#include <bits/stdc++.h>
#define MAXN 200009
using namespace std;
int arr[MAXN];

map<long long,bool> toLeftExists;
map<long long,bool> toRightExists;
map<long long,int> toLeft;
map<long long,int> toRight;

void solve(){
    toLeftExists.clear();
    toRightExists.clear();
    toLeft.clear();
    toRight.clear();
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    long long best = 0;
    long long sumToR = 0, sumToL = 0;
    for(int i = 0; i < N; i ++){
        sumToR += arr[i];
        /*if(toRightExists[sumToR]){
            continue;
        }*/
        toRight[sumToR] = i;
        toRightExists[sumToR] = true;
    }
    for(int j = N - 1; j >= 0; j --){
        sumToL += arr[j];
        toLeft[sumToL] = j;
        toLeftExists[sumToL] = true;
        // cross ref other thing
        if(toRightExists[sumToL]){
            if(toRight[sumToL] < j){
                best = max(best, (long long) (toRight[sumToL] + 1 + (N - 1 - j) + 1));
            }
        }
    }
    cout << best << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --) solve();
    return 0;
}
