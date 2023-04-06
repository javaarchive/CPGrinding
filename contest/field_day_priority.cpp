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
int foundBests = 0;

vector<pair<int,int>> xorResultsByDiffs;

void checkApplyBest(int encoding, int pBest){
    if(best[encoding] < pBest){
        best[encoding] = pBest;
        // these team(s) have found their best
        foundBests += cows[encoding];
    }
}

void check(int diffs, int num){
    for(int cowEncoding: cowsSet){
        int otherEncoding = num ^ cowEncoding;
        if(cows[otherEncoding] > 0 && cowEncoding != otherEncoding){
            checkApplyBest(cowEncoding, diffs);
            checkApplyBest(otherEncoding, diffs);
            // cerr << debugEncodingToOrig[cowEncoding] << " " << debugEncodingToOrig[otherEncoding] << " val " << diffs << endl;
        }else if(cows[otherEncoding] > 1 && cowEncoding == otherEncoding){
            checkApplyBest(cowEncoding, diffs);
            // cerr << debugEncodingToOrig[cowEncoding] << " " << debugEncodingToOrig[otherEncoding] << " val " << diffs << endl;
        }
    }
}

void recurGen(int cowIdx, int diffs,int num){
    if(cowIdx == C){
        xorResultsByDiffs.push_back(make_pair(diffs, num));
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
    // most diffs first
    sort(xorResultsByDiffs.begin(), xorResultsByDiffs.end(), [](pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    });
    for(auto p: xorResultsByDiffs){
        check(p.first, p.second);
        if(foundBests == N) break;
    }

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
