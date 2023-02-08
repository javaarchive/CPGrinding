#include <bits/stdc++.h>
using namespace std;
int N;

char grid[9][9];

int get(int i, int j){
    if(i < 0 || i >= 8) return 0;
    if(j < 0 || j >= 8) return 0;
    return grid[i][j] == '#';
}

void solve(){
    for(int i = 0; i < 8; i ++){
        cin >> grid[i];
    }
    for(int i = 1; i < 7; i ++){
        for(int j = 1; j < 7; j ++){
            if(grid[i][j] == '#'){
                if(grid[i - 1][j - 1] == '#' && grid[i + 1][j - 1] == '#'){
                    if(grid[i - 1][j + 1] == '#' && grid[i + 1][j + 1] == '#'){
                        cout << (i + 1) << " " << (j + 1) << endl;
                        return;
                    }
                }
            }
        }
    }
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(get(i,j)){
                int sum = get(i - 1,j - 1) + get(i + 1,j - 1) + get(i - 1,j + 1) + get(i + 1,j + 1);
                if(sum == 2){
                    cout << (i + 1) << " " << (j + 1) << endl;
                    return;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;    
    while(T --) solve();
    return 0;
}
