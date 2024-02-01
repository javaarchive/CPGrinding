#include <bits/stdc++.h>
#define MAXN 200002
using namespace std;

map<int,vector<int>> adjlist;
map<int,int> parents;

int N;
int P;


void solve(){
    adjlist.clear();

    cin >> N;

    int p;

    for(int i = 0; i < N; i ++){
        cin >> p;
        p --;
        // i to p
        if(i == p){
            // parent
            P = p;
        }else{
            adjlist[i].push_back(p);
            adjlist[p].push_back(i);
        }

        parents[i] = p;
    }
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}