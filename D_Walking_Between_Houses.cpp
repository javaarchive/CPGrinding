#include <bits/stdc++.h>
using namespace std;

int N, K, S;
// K moves
// S distance

void solve(){
    cin >> N >> K >> S;
    int remainingMoves = K;
    int remainingDist = S;
    int rDelta;
    int curPos = 1;
    while(remainingMoves > 0){
        rDelta = remainingDist - remainingMoves;
        // We want to spam a jump
        int jumpA = curPos - 1;
        int jumpB = N - curPos;
        int bestJump = max(jumpA, jumpB);
        if(bestJump > rDelta){
            
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
