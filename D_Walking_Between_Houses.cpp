#include <bits/stdc++.h>
using namespace std;

long long N, K;
long long S;
// K moves
// S distance

void solve(){
    cin >> N >> K >> S;
    long long remainingMoves = K;
    long long remainingDist = S;
    long long rDelta = __LONG_LONG_MAX__;  
    long long curPos = 1;
    vector<long long> out;
    while(remainingMoves > 0 && rDelta > 0){
        // we want this to be equal for freedom to move!
        rDelta = remainingDist - remainingMoves;
        // We want to spam a jump
        long long cap = remainingDist;
        long long jumpA = min(min(curPos - 1, rDelta + 1),cap); // cap it at remaining dist
        long long jumpB = min(min(N - curPos, rDelta + 1), cap); // cap it at remaining dist
        // int bestJump = max(jumpA, jumpB);
        // cout << " rd " << rDelta << " " << jumpA << " " << jumpB << " to " << endl;
        if(jumpA > jumpB && curPos > 1){
            // Jump left
            // cout << "L";
            curPos -= jumpA;
            remainingMoves -= 1;
            remainingDist -= jumpA;
            out.push_back(curPos);
        }else if(jumpA <= 0 && jumpB <= 0){
            break;
        }else{
            // Jump right
            // cout << "R";
            curPos += jumpB;
            remainingMoves -= 1;
            remainingDist -= jumpB;
            out.push_back(curPos);
        }
    }
    // for(int i: out) cout << i << " ";
    cout << endl;
    rDelta = remainingDist - remainingMoves;
    // cout << rDelta << " " << remainingMoves << " " << remainingDist << " " << curPos << endl;
    while(remainingMoves > 0ll && remainingDist > 0ll){
        if(curPos == N){
            curPos -= 1;
            remainingMoves -= 1;
            remainingDist -= 1;
            out.push_back(curPos);
            // cout << " - ->" <<  curPos << " ";
            // cout << curPos << " ";
        }else{
            curPos += 1;
            remainingMoves -= 1;
            remainingDist -= 1;
            out.push_back(curPos);
            // cout << " + ->" <<  curPos << " ";
            // cout << curPos << " ";
        }
    }
    if(remainingMoves > 0 || remainingDist > 0){
        // cout << remainingMoves << " " << remainingDist << " " << curPos << endl;
        cout << "NO" << endl;
        /*for(int i = 0; i < out.size(); i++){
            cout << out[i] << " ";
        }*/
        return;
    }
    cout << "YES" << endl;
    for(int i = 0; i < out.size(); i++){
        cout << out[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    solve();   
    return 0;
}
