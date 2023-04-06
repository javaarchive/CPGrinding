#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int powof2[28];
int C, N;
int best[262145] = {0};
int cows[262145] = {0};
// int debugEncodingToOrig[262145] = {0};
unordered_set<int> cowsSet;
int order[MAXN];

void check(int diffs, int num){
    for(int cowEncoding: cowsSet){
        int otherEncoding = num ^ cowEncoding;
        if(cows[otherEncoding] > 0 && cowEncoding != otherEncoding){
            best[cowEncoding] = max(best[cowEncoding] , diffs);
            best[otherEncoding] = max(best[otherEncoding], diffs);
            // cerr << debugEncodingToOrig[cowEncoding] << " " << debugEncodingToOrig[otherEncoding] << " val " << diffs << endl;
        }else if(cows[otherEncoding] > 1 && cowEncoding == otherEncoding){
            best[cowEncoding] = max(best[cowEncoding] , diffs);
            // cerr << debugEncodingToOrig[cowEncoding] << " " << debugEncodingToOrig[otherEncoding] << " val " << diffs << endl;
        }
    }
}

void recurGen(int cowIdx, int diffs,int num){
    if(cowIdx == C){
        check(diffs, num);
    }else{
        recurGen(cowIdx + 1,diffs + 1, num + powof2[cowIdx]);
        recurGen(cowIdx + 1,diffs, num);
    }
}

void solve(){
    cin >> C >> N;
    string line;
    for(int i = 0; i < N; i ++){
        int encoding = 0;
        cin >> line;
        for(int j = 0; j < C; j ++){
            if(line[j] == 'H') encoding += powof2[j];
        }
        // cerr << "Line " << i << " encoded to " << encoding << endl;
        cows[encoding] ++;
        // debugEncodingToOrig[encoding] = i;
        cowsSet.insert(encoding);
        order[i] = encoding;
    }
    recurGen(0,0,0);
    // cout << best << endl;
    for(int i = 0; i < N; i ++){
        cout << best[order[i]] << endl;
    }
}

int main(int argc, char const *argv[])
{
    // prefill
    for(int i = 0; i < 20; i ++){
        powof2[i] = 1 << i;
    }
    solve();
    return 0;
}
