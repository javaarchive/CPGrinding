#include <bits/stdc++.h>
#define MAXN 101
using namespace std;

int grid[MAXN][MAXN];
string line;
int vals[4];

void solve(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> line;
        for(int j = 0; j < N; j ++){
            grid[i][j] = line[j] - '0';
        }
    }

    int mid1 = N/2;
    int mid2 = (N % 2 == 1) ? floor(N/2):N/2 - 1;
    int mid3 = (N % 2 == 1) ? floor(N/2):N/2;

    int ans = 0;

    // quad order
    // AB
    // DC

    int originQuadAx = mid2;
    int originQuadAy = mid2; 
    int originQuadBx = mid2;
    int originQuadBy = mid3; 
    int originQuadCx = mid3;
    int originQuadCy = mid3; 
    int originQuadDx = mid3;
    int originQuadDy = mid2;
    // cout << "m " << mid1 << " " << mid2 << " " << mid3 << endl; 
    // cout << "og B: " << originQuadBx << " " << originQuadBy << endl; 

    for(int i = 0; i < mid1; i ++){
        for(int j = 0; j <= mid2; j ++){
            int vecX = originQuadAx - i;
            int vecY = originQuadAy - j;
            int bX = originQuadBx - vecY;
            int bY = originQuadBy + vecX;
            int cX = originQuadCx + vecX;
            int cY = originQuadCy + vecY;
            int dX = originQuadDx + vecY;
            int dY = originQuadDy - vecX;
            // cout << i << " " << j;
            // cout << " vecx:" << vecX << " vecy: " << vecY << " and " << bX << " " << bY << " , " << cX << " " << cY << " , and " << dX << " " << dY << endl;
            vals[0] = grid[i][j];
            vals[1] = grid[bX][bY];
            vals[2] = grid[cX][cY];
            vals[3] = grid[dX][dY];
            // cout << "VALS " << vals[0] << " " << vals[1] << " " << vals[2] << " " << vals[3] << endl;
            int count1 = vals[0] + vals[1] + vals[2] + vals[3];
            int count0 = 4 - count1;
            ans += min(count0,count1);
        }
    }

    cout << ans << endl;
    // cout << "===" << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --) solve();
    return 0;
}
