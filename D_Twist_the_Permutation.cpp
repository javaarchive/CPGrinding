#include <bits/stdc++.h>
#define MAXN 2002

using namespace std;

int target[MAXN];
int N;

map<int,int> invIndex;

int shift = 0;

int shiftCounts[MAXN];



void solve(){
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> target[i];
        invIndex[target[i]] = i;
    }
    
    
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i ++){
        solve();
        
    }
    return 0;
}