#include <bits/stdc++.h>
#define MAXDIM 1004

using namespace std;

int N,Q;

void solve(){
    long long areaSpace[MAXDIM][MAXDIM] = {0};
    long long psSpace[MAXDIM][MAXDIM] = {0};

    for(int i = 0; i < MAXDIM; i ++){
        for(int j = 0; j < MAXDIM; j ++){
            areaSpace[i][j] = 0;
        }
    }

    cin >> N >> Q;
    for(int i = 0; i < N; i ++){
        int rW, rH;
        cin >> rW >> rH;
        areaSpace[rW][rH] += rW * rH; // area
    }
    // generate ps
    // edges
    for(int i = 1; i < MAXDIM; i ++){
        psSpace[0][i] = areaSpace[0][i] + psSpace[0][i - 1];
    }
    for(int i = 1; i < MAXDIM; i ++){
        psSpace[i][0] = areaSpace[i][0] + psSpace[i - 1][0];
    }
    // inner
    for(int i = 1; i < MAXDIM; i ++){
        for(int j = 1; j < MAXDIM; j ++){
            psSpace[i][j] += psSpace[i - 1][j] + psSpace[i][j - 1] - psSpace[i - 1][j - 1] + areaSpace[i][j];
        }
    }
    // end ps build
    // query answering time

    // Debug
    /*if(true){
        cout << "Prefix Sums " << endl;
        for(int i = 0; i < 15; i ++){
            for(int j = 0; j < 15; j ++){
                cout << psSpace[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/

    for(int i = 0 ; i < Q; i ++){
        int W1,H1,W2,H2;
        cin >> W1 >> H1 >> W2 >> H2;
        W2 --;
        H2 --;
        H1 ++;
        W1 ++;
        
        // query
        long long ans = 0;
        ans += psSpace[W2][H2];
        ans -= psSpace[W2][H1 - 1];
        ans -= psSpace[W1 - 1][H2];
        ans += psSpace[W1 - 1][H1 - 1];
        cout << ans << endl;
    }    
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}