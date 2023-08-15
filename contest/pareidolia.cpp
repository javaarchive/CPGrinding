#include <bits/stdc++.h>
#define MAXL 300001

using namespace std;

string line;

const int PATTERNLEN = 6;
string PATTERN = "bessie";
int patternIndex = 0;
int patternStart = -1;
int patternEnd = -1;

int markerStart[MAXL];
int markerEnd[MAXL];
int wordMask[MAXL] = {0};
int startToEnd[MAXL];

// int psStart[MAXL];
// int psEnd[MAXL];

int L;

void debugOverlay(){
    for(int i = 0; i < L; i ++){
        cerr << wordMask[i];
    }
    cerr << endl;
    for(int i = 0; i < L; i ++){
        cerr << markerStart[i];
    }
    cerr << endl;
    cerr << line << endl;
    for(int i = 0; i < L; i ++){
        cerr << markerEnd[i];
    }
    cerr << endl;
}

void solve(){
    cin >> line;
    L = line.length();
    for(int i = 0; i < L; i ++){
        if(line[i] == PATTERN[patternIndex]){
            if(patternIndex == 0) patternStart = i;
            patternIndex ++;
            if(patternIndex == PATTERNLEN){ // pattern fully matched
                patternEnd = i;
                // save
                markerStart[patternStart] = 1;
                markerEnd[patternEnd] = 1;
                for(int j = patternStart; j <= patternEnd; j ++){
                    wordMask[j] = 1;
                }
                startToEnd[patternStart] = patternEnd;
                // reset
                patternIndex = 0;
            }
        }
    }
    // debugOverlay();
    long long ans = 0;
    // pass one time fully
    int beginHits = 0;
    int endHits = 0;
    long long adding = 0;
    // brute sweep fully once
    for(int i = 0; i < L; i ++){
        if(markerStart[i] == 1){
            beginHits ++;
        }
        if(markerEnd[i] == 1){
            endHits ++;
        }
        adding += min(beginHits, endHits);
    }
    ans += adding;
    // cout << "KEKW init " << ans << endl;
    for(int i = 1; i < L; i ++){
        if(markerStart[i - 1] == 1){
            beginHits --;
            int endingPos = startToEnd[i - 1];
            adding -= (L - endingPos);
        }else{
            // adding -= 1;
        }
        
        // if we just deleted a space we...
        if(markerEnd[i - 1] == 1){
            endHits --;
        }
        // cout << i << " " << adding << endl;
        ans += adding;
    }

    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    solve();   
    return 0;
}
