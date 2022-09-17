#include <bits/stdc++.h>
#define MAXNM 52

using namespace std;

char grid[MAXNM][MAXNM];
int N, M;

struct L{
    pair<int,int> origin;
    pair<int,int> legA;
    pair<int,int> legB;
};

int checkXYnotFilled(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M){ 
        return grid[x][y] != '*';
    }
    return true;
}

void solve(){
    
    cin >> N >> M;
    string line;
    for(int i = 0; i < N; i ++){
        cin >> line;
        for(int j = 0; j < M; j ++){
            grid[i][j] = line[j];
        }
    }
    bool works = true;
    vector<L> lShapes;
    for(int i = 0; i < N - 1; i ++){
        for(int j = 0; j < M - 1; j ++){
            // query 4
            int count = 0;
            count += grid[i][j] == '*';
            count += grid[i + 1][j] == '*';
            count += grid[i][j + 1] == '*';
            count += grid[i + 1][j + 1] == '*';
            if(count == 3){
                // L shape for section
                L lShape;
                if(grid[i][j] == '.'){
                    lShape.origin = make_pair(i + 1, j + 1);
                    lShape.legA = make_pair(i, j + 1);
                    lShape.legB = make_pair(i + 1, j);
                }else if(grid[i + 1][j] == '.'){
                    lShape.origin = make_pair(i, j + 1);
                    lShape.legA = make_pair(i + 1, j + 1);
                    lShape.legB = make_pair(i, j);
                }else if(grid[i][j + 1] == '.'){
                    lShape.origin = make_pair(i + 1, j);
                    lShape.legA = make_pair(i + 1, j + 1);
                    lShape.legB = make_pair(i, j);
                }else if(grid[i + 1][j + 1] == '.'){
                    lShape.origin = make_pair(i, j);
                    lShape.legA = make_pair(i, j + 1);
                    lShape.legB = make_pair(i + 1, j);
                }
                lShapes.push_back(lShape);
            }else if(count == 4){
                // wtf
                // touching
                works = false;
                break;
            }
        }
        if(!works){
            break;
        }
    }

    if(works){
        // so far works
        for(L lShape: lShapes){
            auto origin = lShape.origin;
            auto legA = lShape.legA;
            auto legB = lShape.legB;
            int aX = lShape.legA.first - lShape.origin.first;
            int aY = lShape.legA.second - lShape.origin.second;
            int bX = lShape.legB.first - lShape.origin.first;
            int bY = lShape.legB.second - lShape.origin.second;
            //
            //
            // 
            // 000
            // 0*00
            // 0**0
            // 0000
            if(!checkXYnotFilled(origin + legA)){
                works = false;
                break;
            }
        }
    }

    cout << (works ? "YES" : "NO") << endl;

}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T:
    while(T --) solve();
    return 0;
}
