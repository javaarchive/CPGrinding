#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int N;
string a,b;
int A[MAXN];
int B[MAXN];
int A1[MAXN];
int B1[MAXN];

vector<pair<int,int>> pairs;

int countAll(){
    int count = 0;
    for(int i = 0; i < N; i ++){
        count += (B1[i] == 1)?1:0;
    }
    return count;
}

void solve(){
    cin >> N;
    cin >> a >> b;
    pairs.clear();
    for(int i = 0; i < N; i ++){
        A[i] = a[i] - '0';
        B[i] = b[i] - '0';
        A1[i] = a[i] - '0';
        B1[i] = b[i] - '0';
    }
    int streak = 0;
    int last = -1;
    int streakCount = 0;
    
    for(int i = 0; i < N; i ++){
        if(A[i] == 0 && last == 1){
            streak = 0;
            // end streak
            pair<int,int> p = make_pair(i - streak, i - 1);
            pairs.push_back(p);
            streakCount ++;
        }else{
            streak ++;
        }
        last = A[i];
    }
    if(A[N - 1] == 1){
        pair<int,int> p = make_pair(N - streak, N - 1);
        pairs.push_back(p);
        streakCount ++;
    }

    for(int i = 0; i < N; i ++){
        A1[i] = 0;
        int flips = streakCount;
        if(A[i] == 1){
            // don't flip ourself extra
            flips --;
        }
        B1[i] = (B1[i] + flips) % 2;
    }
    /*cout << endl;
    for(int i = 0; i < N; i ++){
        cout << A1[i];
    }
    cout << endl;
    for(int i = 0; i < N; i ++){
        cout << B1[i];
    }
    cout << endl;*/
    
    int outCount = pairs.size();
    int ca = countAll();
    if(ca == N){
        if(N == 1){
            cout << "NO" << endl;
            return;
        }
        outCount += 3;
    }else if(ca != 0){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << outCount << endl;
    for(auto p: pairs){
        cout << (p.first + 1) << " " << (p.second + 1) << endl;
    }
    if(ca == N){
        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << N << endl;
        cout << 1 << " " << N << endl;
    }
    // bottom B is filled with ones so we need to perform operation
    
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();   
    return 0;
}
