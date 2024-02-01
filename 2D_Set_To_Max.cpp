#include <bits/stdc++.h>
#define MAXN 200002
using namespace std;

int N;
int arr[MAXN];
int target[MAXN];

bool leftOk[MAXN];
bool rightOk[MAXN];

void solve(){
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    for(int i = 0; i < N; i ++){
        cin >> target[i];
    }
    for(int i= 0; i < N; i ++){
        if(target[i] < arr[i]){
            cout << "NO" << endl;
        }
    }

    fill(leftOk, leftOk + N, false);
    fill(rightOk, rightOk + N, false);

    stack<int> lStk;

    for(int i = 0; i < N; i ++){
        while(!lStk.empty()){
            if(arr[i] > lStk.top()){
                lStk.pop();
            }
        }
        // lStk.push()
    }

    cout << "YES" << endl;
    return;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}