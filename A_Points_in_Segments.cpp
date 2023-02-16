#include <bits/stdc++.h>

using namespace std;

#define MAXNM 202

int arr[MAXNM];
int N, M;

void solve(){
    cin >> N >> M;
    for(int i = 0; i < MAXNM; i ++){
        int a,b;
        cin >> a >> b;
        for(int i = a; i <= b; i ++){
            arr[i] += 1;
        }
    }
    int count = 0;
    for(int i = 1; i <= M; i ++){
        if(arr[i] != 0) continue;
        count += 1;
    }
    cout << count << endl;
    for(int i = 1; i <= M; i ++){
        if(arr[i] != 0) continue;   
        cout << i << " ";
    }

}

int main(int argc, char const *argv[])
{
    solve();    
    return 0;
}
