#include <bits/stdc++.h>
#define MAXNM 201
using namespace std;

int N, M;
int grid[MAXNM][MAXNM];
long long sumA[MAXNM][MAXNM];
long long sumB[MAXNM][MAXNM];
// int bestA = 0;
// int bestB = 0;

bool check(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void scanA(int bx, int by){
    int cx = bx;
    int cy = by;
    long long cur = 0;
    while(check(cx,cy)){
        cur += grid[cx][cy];
        // move
        cx += 1;
        cy += 1;
    }
    // bestA = max(bestA, cur);
    // reset and set sum
    cx = bx;
    cy = by;
    while(check(cx,cy)){
        sumA[cx][cy] = cur;
        // move
        cx += 1;
        cy += 1;
    }
}

void scanB(int bx, int by){
    int cx = bx;
    int cy = by;
    long long cur = 0;
    while(check(cx,cy)){
        cur += grid[cx][cy];
        // move
        cx += 1;
        cy -= 1;
    }
    // bestB = max(bestB, cur);
    // reset and set sum
    cx = bx;
    cy = by;
    while(check(cx,cy)){
        sumB[cx][cy] = cur;
        // move
        cx += 1;
        cy -= 1;
    }
}

void solve(){
    cin >> N >> M;
    // reset
    // bestA = 0;
    // bestB = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            cin >> grid[i][j];
            sumA[i][j] = 0;
            sumB[i][j] = 0;
        }
    }

    scanA(0,0);
    for(int i = 1; i < N; i ++){
        scanA(i, 0);
    }
    for(int i = 1; i < M; i ++){
        scanA(0, i);
    }

    scanB(0,0);
    for(int i = 1; i < N; i ++){
        scanB(i, M - 1);
    }
    for(int i = 0; i < M; i ++){
        scanB(0, i);
    }
    long long best = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            best = max(best, sumA[i][j] + sumB[i][j] - grid[i][j]);
        }
    }
    cout << best << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}