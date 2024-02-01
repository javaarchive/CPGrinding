#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int N, Q, C;

int mins[MAXN];
int maxs[MAXN];

unordered_map<int, vector<int>> implies; // reaching a point going backwards that has a key here, you should set upper bound
unordered_map<int, vector<int>> reverse_implies;

vector<pair<int,int>> constriants;

void solve(){
    cin >> N >> Q >> C;
    fill(mins, mins + N, 1);
    fill(maxs, maxs + N, C);
    for(int i = 0; i < N; i ++){
        // known
        int c = 0;
        cin >> c;
        if(c != 0){ // lock value
            mins[i] = c;
            maxs[i] = c;
        }
    }

    constriants.clear();
    implies.clear();
    reverse_implies.clear();
    for(int i = 0; i < Q; i ++){
        int a, b;
        // a < b
        cin >> a >> b;
        // c indexes start at 0
        a --;
        b --;
        // old hack
        // a = b - 1;
        constriants.push_back(make_pair(a,b));
    }
    sort(constriants.begin(), constriants.end(), [](auto a, auto b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.second;
    });
    // so these things show up in the map as sorted vector order
    /*if(Q != constriants.size()){
        cout << "WTF" << endl;
    }*/
    for(auto pair: constriants){
        implies[pair.first].push_back(pair.second);
        reverse_implies[pair.second].push_back(pair.first);
    }

    int maximumValue, minimumValue, maximumValue2;

    for(int i = 0; i < N; i ++){
        if(implies[i].size() > 1){
            // contradict
            cout << -1 << endl;
            return;
        }
    }

    // let's start implying the things
    for(int p = 0; p < 1; p ++){ // double pass
        minimumValue = 1;
        maximumValue2 = C;
        for(int i = 0; i < N; i ++){
            minimumValue = max(minimumValue, mins[i]);
            maxs[i] = min(maxs[i], maximumValue2);
            if(implies.find(i) != implies.end()){
                for(int therefore: implies[i]){
                    // cout << "[" << i << "] implies " << therefore << " is " << minimumValue << endl;
                    mins[therefore] = max(minimumValue + 1, mins[therefore]); // needs to be larger than the maxes of mins
                    // numbers after cannot be greater than the current min
                    // maximumValue2 = minimumValue;
                }
            }
        }

        // reverse pass
        maximumValue = C;
        for(int i = N - 1; i >= 0; i --){
            if(implies.find(i) != implies.end()){
                for(int therefore: implies[i]){
                    maximumValue = min(maximumValue, maxs[therefore] - 1);
                }
            }
            // cout << " i " << i << endl;
            maxs[i] = min(maxs[i], maximumValue);
        }
    }

    // extra checker hack?
    vector<int> maxesUpTo;
    int temp = 1;
    for(int i = 0; i < N; i ++){
        temp = max(temp, maxs[i]);
        maxesUpTo.push_back(temp);
    }

    multiset<int> cur_maxes;
    for(int i = 0; i < N; i ++){
        if(reverse_implies.find(i) != reverse_implies.end()){
            for(int edge: reverse_implies[i]){
                cur_maxes.erase(maxesUpTo[edge]);
                cur_maxes.erase(maxs[i] - 1);
            }
        }
        if(!cur_maxes.empty()){
            // can only be at most
            int maximumSeg = *cur_maxes.begin();
            cout << i << " maximum " << maximumSeg << endl;
            maxs[i] = min(maxs[i], maximumSeg);
        }

        if(implies.find(i) != implies.end()){
             for(int endp: implies[i]){
                cur_maxes.insert(maxesUpTo[i]);
                cur_maxes.insert(maxs[endp] - 1);
            }
        }
    }


    for(int i = 0; i < N; i ++){
        if(mins[i] > maxs[i]){ // solve failure.
            cout << -1 << endl;
            // debug
            // print minimal achievable
            /*for(int i = 0; i < N; i ++){
                cout << maxs[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < N; i ++){
                cout << mins[i] << " ";
            }
            cout << endl;*/
            return;
        }
    }

    // print minimal achievable
    for(int i = 0; i < N; i ++){
        cout << maxs[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i ++){
        cout << mins[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}