#include <bits/stdc++.h>
#define MAXNM 201

using namespace std;

int N, M;

int grid[MAXNM][MAXNM];


int pairToInt(pair<int,int> p){
    return p.first * (M + 1) + p.second;
}

unordered_map<int, int> sumP;
unordered_map<int, int> sumN;

void traverseP(pair<int,int> base, pair<int,int> inc){
    pair<int,int> cur;
    cur = make_pair(base.first, base.second);
    while(true){
        sumP[pairToInt(base)] += grid[cur.first][cur.second];
        cur.first += inc.first;
        cur.second += cur.second;
        if(cur.first >= N || cur.second >= M || cur.first < 0 || cur.second < 0){
            return;
        }
    }
}
void traverseN(pair<int,int> base, pair<int,int> inc){
    pair<int,int> cur;
    cur = make_pair(base.first, base.second);
    while(true){
        sumN[pairToInt(base)] += grid[cur.first][cur.second];
        cur.first += inc.first;
        cur.second += inc.second;
        if(cur.first >= N || cur.second >= M || cur.first < 0 || cur.second < 0){
            cout << base.first << "," << base.second << " ended at " << cur.first << "," << cur.second <<  " = " << sumN[pairToInt(base)] << endl;
            return;
        }
    }
    
}

int incLen(pair<int,int> base, pair<int,int> inc){
    int x,y;
    if(inc.first > 0){
        x = N - 1 - base.first;
    }else{
        x = N - 
    }
    if(inc.second > 0){

    }else{

    }
    return make_pair(x,y);
}

void solve(){
    cin >> N >> M;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            cin >> grid[i][j];   
        }
    }
    const pair<int,int> POSITIVE = make_pair(1,1);
    const pair<int,int> NEGATIVE = make_pair(-1,1);
    for(int i = 0; i < N; i ++){
        traverseP(make_pair(i,0), POSITIVE);
    }
    for(int i = 1; i < M; i ++){
        traverseP(make_pair(0,i), POSITIVE);
    }
    for(int i = 0; i < N; i ++){
        traverseN(make_pair(i,0), make_pair(-1,1));
    }
    for(int i = 1; i < M; i ++){
        traverseN(make_pair(0,i), make_pair(1,-1));
    }

    long long best = 0;
    
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            int val = grid[i][j];
            int minCoord = min(i,j);
            int wallY = min(i + j,M - 1);
            int move = incLen(make_pair(i,j),NEGATIVE);
            auto TL = make_pair(i - minCoord,j - minCoord);
            auto TR = make_pair(i - move,j + move);
            cout << "TR target " << TR.first << " " << TR.second << endl;

            cout << sumP[pairToInt(TL)] << " + " << sumN[pairToInt(TR)] << " - " << val << endl;

            long long sum = sumP[pairToInt(TL)] + sumN[pairToInt(TR)] - val;
            best = max(best, sum);
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
