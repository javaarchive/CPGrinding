#include <bits/stdc++.h>
#define int long long
#define MAXN 200001
using namespace std;

map<int,vector<int>> graph;

map<int,int> longestPath;

int depths[MAXN];
int origins[MAXN];
int otherTable[MAXN];
int otherOrigin[MAXN];

const int INIT_ROOT = 1;

int dfs(int node, int parent, int depth, int origin){
    int maximumDepth = 0; // if I had no children then I have a longest path of 0
    depths[parent] = depth - 1; // just in case, mainly meant to cover the root
    depths[node] = depth;
    origins[node] = origin;
    for(int child: graph[node]){
        if(child == parent) continue;
        // cout << node << " -> " << child << endl;
        maximumDepth = max(maximumDepth, dfs(child, node, depth + 1, origin) + 1);
    }
    // cout << "DFS " << node << " md: " << maximumDepth << endl;
    longestPath[node] = maximumDepth;
    return maximumDepth;
}



void redfs(int node, int parent, int signal, int signalOrigin){
    int max1Branch = signalOrigin;
    int max1Value = signal;
    int max2Branch = signalOrigin;
    int max2Value = signal;

    // children
    //cout << "Children of " << node << endl;
    /*for(int child: graph[node]){
        cout << child << " ";
    }
    cout << endl;*/
    /*for(int child: graph[node]){
        if(child == parent) continue;
        cout << longestPath[child] << " ";
    }
    cout << endl;*/

    //if(signal == -1){
        for(int child: graph[node]){
            if(child == parent) continue;
            int childLp = longestPath[child] + 1;
            // cout << "lpl " << child << " " << childLp << endl;
            if(childLp > max1Value){
                max2Branch = max1Branch;
                max2Value = max1Value;
                
                max1Value = childLp;
                max1Branch = child;
            } else if(max1Branch > -1 && longestPath[child] > max2Value){
                max2Value = childLp;
                max2Branch = child;
            }
        }
    //} else {
        // max1Branch = signal; // use a node from higher up
    //}
    // cout << "max lps " << max1Value << " " << max2Value << endl;
    //cout << "priorities n" << node << " n" << max1Branch << " n" << max2Branch << endl;

    // tell our children if we have an adjacent branch ready to be used

    // cout << " get " << node << endl;

    auto children = graph[node];
    for(int child: children){
        if(child == parent) continue;
        if(child == max1Branch){
            redfs(child, node, max2Value + 1, max2Branch);
        }else{
            redfs(child, node, max1Value + 1, max1Branch);
        }
    }

    // update ourself

    otherTable[node] = signal + 1;
    otherOrigin[node] = signalOrigin;
}

void solve(){
    // cout << "=== SOLVE ===" << endl;
    int N;
    long long K, C;
    cin >> N >> K >> C;
    // reset
    graph.clear();
    longestPath.clear();
    for(int i = 0; i < N - 1; i ++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // fill(origins, origins + MAXN, -1);
    // fill(depths, depths + MAXN, -1);

    // vector<long long> rootPathLens;
    // vector<pair<long long, int>> adjLongPaths;

    // also overwrites the depths
    origins[INIT_ROOT] = INIT_ROOT;
    int lpRoot = 0;
    for(int v: graph[INIT_ROOT]){
        longestPath[v] = dfs(v, INIT_ROOT, 1, v);
        lpRoot = max(longestPath[v] + 1, lpRoot);
        // rootPathLens.push_back(longestPath[v]);
        // adjLongPaths.push_back(make_pair(longestPath[v],v));
    }
    longestPath[INIT_ROOT] = lpRoot;

    /*for(int v: graph[INIT_ROOT]){
        redfs(v, 1, -1, -1);
    }*/
    redfs(1,1,-1,-1); // our parent is ourself because this is only to make sure we don't loop

    // sort(rootPathLens.begin(), rootPathLens.end());
    // reverse(rootPathLens.begin(), rootPathLens.end());

    // sort(adjLongPaths.begin(), adjLongPaths.end());
    // reverse(adjLongPaths.begin(), adjLongPaths.end());

    /*cout << "lps: ";

    /*for(int p: rootPathLens){
        cout << p << " ";
    }*/

    /*for(int i = 1; i <= N; i ++){
        cout << longestPath[i] << " ";
    }

    cout << endl;*/

    /*cout << "otherTable: ";
    for(int i = 1; i <= N; i ++){
        cout << otherTable[i] << " ";
    }
    cout << endl;
    cout << "otherOrigin: ";
    for(int i = 1; i <= N; i ++){
        cout << otherOrigin[i] << " ";
    }
    cout << endl;*/

    /*if(rootPathLens.size() == 0){
        // wtf we're lonely?
        // impossible but ok
        cout << 0 << endl;
        return;
    }*/

    int best = 0;

    /*if(C >= K || rootPathLens.size() == 1){
        // unprofitable
        best = ((rootPathLens[0] + 1) * K);
    }else{
        // cout << "P " << (rootPathLens[0] + 1) << "*" << K << " + " << (rootPathLens[1] + 1) << "* (" << K << " - " << C << ")" << endl;
        best = ((rootPathLens[0] + 1) * K + (rootPathLens[1] + 1) * (K - C));
    }*/

    // if(adjLongPaths.size() > 1){ // possibly not be able to pick alt using original root paths?
        for(int root = 1; root <= N; root ++){
            long long cost = depths[root] * C; // movement cost
            // +1 offset for edge between adjacent and shared node
            // +1 depth diff
           
            long long other = 0;
            if(root != INIT_ROOT && otherOrigin[root] != -1){
                // cout << "root " << root << " ot->" << otherTable[root] << endl;
                // cout << " other calc use " << depths[root] << " - " << depths[otherOrigin[root]] << " + 1 + " << otherTable[root] << " other origin " << otherOrigin[root] << " we are currently " << depths[root] << " deep" << endl;
                other = otherTable[root] - 1;
                // cout << " calculated: " << other << endl;
            }
            /*if(origins[root] == adjLongPaths[0].second){
                if(adjLongPaths.size() == 1){
                    // cout << "OOP" << endl;
                    
                    // continue;
                }
                other = adjLongPaths[1].first + 1;
            }*/
            // cout << "root " << root << " lp " << (longestPath[root]) << " other " << other << " + depth of root is " << depths[root] << endl;
            //                     go "down"         go back to orig root + down some other thing
            // cout << "max(" << longestPath[root] << "," << other << ")" << endl;
            long long value = max(longestPath[root], other) * K;
            // cout << "reroot " << root << " = " << value << " profit " << (value - cost) << endl;
            best = max(value - cost, best);
        }
    // }

    cout << best << endl;

}

signed main(signed argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}