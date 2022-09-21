#include <bits/stdc++.h>
#define MAXNM 52

using namespace std;

char grid[MAXNM][MAXNM];
bool visited[MAXNM][MAXNM];
int N, M;

int compID;

int dirX[8] = {-1,1,0,0,-1,1,-1,1};
int dirY[8] = {0,0,-1,1 ,-1,1,1,-1};

void solve(){
    
    cin >> N >> M;
    string line;
    compID = 0;
    for(int i = 0; i < N; i ++){
        cin >> line;
        for(int j = 0; j < M; j ++){
            grid[i][j] = line[j];
            visited[i][j] = false;
        }
    }

    bool works = true;

    vector<vector<pair<int,int>>> components;
    for(int i = 0 ; i < N; i ++){
        for(int j = 0; j < M; j ++){
            if(!visited[i][j] && grid[i][j] == '*'){
                // dfs time
                stack<pair<int,int>> next;
                vector<pair<int,int>> comp;
                next.push(make_pair(i,j));
                while(!next.empty()){
                    pair<int,int> pos = next.top();
                    next.pop();
                    comp.push_back(pos);
                    // redundant but for first
                    visited[pos.first][pos.second] = true;
                    for(int k = 0; k < 8; k ++){
                        int newX = pos.first + dirX[k];
                        int newY = pos.second + dirY[k];
                        
                        if(0 <= newX && newX < N){
                            if(0 <= newY && newY < M){
                                if(!visited[newX][newY] && grid[newX][newY] == '*'){
                                    // add
                                    visited[newX][newY] = true;
                                    next.push(make_pair(newX, newY));
                                }
                            }
                        }
                    }
                }
                
                components.push_back(comp);
                compID ++;
            }
        }
    }

    // Iterate every component and check length
    for(vector<pair<int,int>> comp: components){
        if(comp.size() != 3){
            works = false;
            // cout << "Size test failed " << comp.size() << endl; 
            break;
        }
        // Calculate area
        int minX = INT32_MAX;
        int minY = INT32_MAX;
        int maxX = -1;
        int maxY = -1;
        for(pair<int,int> pos: comp){
            minX = min(pos.first, minX);
            maxX = max(pos.first, maxX);
            minY = min(pos.second, minY);
            maxY = max(pos.second, maxY);
        }
        // area must be 4 in a square 2x2
        if((maxX - minX) != 1 || (maxY - minY) != 1){
            works = false;
            // cout << "Area test failed " << minX << "," << minY << " < " << maxX << "," << maxY << endl;
            break;
        }
    }

    cout << (works ? "YES" : "NO") << endl;

}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
