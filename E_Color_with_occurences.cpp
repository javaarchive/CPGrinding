#include <bits/stdc++.h>
#define MAXT 102
#define MAXN 102

using namespace std;

int N, T;
string str;
int lengths[MAXN];

void solve(){
    cin >> str;
    T = str.length();
    cin >> N;
    vector<string> substrs;
    //          substr id  pos
    // vector<pair<int       ,   int>> choices;
    vector<int> insertables[MAXT]; 
    for(int i = 0; i < N; i ++){
        string substr;
        cin >> substr;
        int K = substr.length();
        substrs.push_back(substr);
        lengths[i] = K;
        // quick dumb match
        for(int j = 0; j < T - K + 1; j ++){
            bool works = true;
            for(int k = 0; k < K; k ++){
                if(str[j + k] != substr[k]){
                    works = false;
                    break;
                }
            }
            if(works){
                // cout << substr << " matched at " << j << endl;
                // choices.push_back(make_pair(i,j));
                insertables[j].push_back(i); 
            }
        }
    }

    int total = 0;
    // bool colored[MAXT] = {0};

    int howWeGetHere[MAXT] = {INT32_MAX}; // mc ref
    int howDidWeGetHere[MAXT] = {INT32_MAX}; // mc ref, goes to previous index
    int howDidWeGetHereSIDs[MAXT] = {INT32_MAX}; // substring ids
    fill(howWeGetHere, howWeGetHere + MAXT, INT32_MAX);
    fill(howDidWeGetHere, howDidWeGetHere + MAXT, INT32_MAX);
    fill(howDidWeGetHereSIDs, howDidWeGetHereSIDs + MAXT, INT32_MAX);
    howWeGetHere[0] = 0; // base
    for(int i = 0; i < T; i ++){
        int best = 0;
        // for(int j = 0; j <= i; j ++){
            for(int si: insertables[i]){// - j]){
                int len = lengths[si];
                int dest = i + len; //i + len - j; // we went back j steps
                int newVal = howWeGetHere[i] + 1;
                for(int k = 1; k <= len; k ++){
                    int writeTo = i + k;
                    if(writeTo > T) break; // out of bounds write
                    if(howWeGetHere[writeTo] > newVal){
                        // cout << "DP " << i << " -> " << writeTo << " writing " << newVal << endl;
                        howDidWeGetHere[writeTo] = i;
                        howDidWeGetHereSIDs[writeTo] = si;
                        howWeGetHere[writeTo] = newVal;
                    }
                }
            }
        // }
    }

    if(howWeGetHere[T] == INT32_MAX){
        cout << -1 << endl;
        return;
    }

    cout << howWeGetHere[T] << endl;
    // we trace cause I did horrible design
    // but we don't care order :P
    int index = T;
    // int sanity = 0;
    /*for(int i = 0; i < N; i ++){
        cout << howDidWeGetHereSIDs
    }
    cout << endl;*/
    while(howDidWeGetHere[index] != INT32_MAX){
        cout << howDidWeGetHereSIDs[index] + 1 << " " << howDidWeGetHere[index] + 1 << endl;
        // cout << "INDEX " << index << endl;
        index = howDidWeGetHere[index];
        // sanity ++;
    }
}

// help

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --){
        solve();
    }
    return 0;
}