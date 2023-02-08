#include <bits/stdc++.h>
using namespace std;
#define MAXN 200002

int N;
long long total, avg;
long long weights[MAXN];

unordered_map<int, vector<int>> adjList;

struct Command{
    int src, dst, amount;
};

vector<Command> output;

void solve(){
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> weights[i - 1];
        total += weights[i - 1];
    }
    avg = total / N;
    for(int i = 0; i < N - 1; i ++){
        int a,b;
        cin >> a >> b;
        a --;
        b --;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    bool allClear = false;
    while(!allClear){
        allClear = true;
        for(int i = 0; i < N; i ++){
            if(weights[i] > avg){
                // Distribute
                // bool usedObviousSpread = false;
                // for(int adjNode: 
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
