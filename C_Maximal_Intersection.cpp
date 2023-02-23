#include <bits/stdc++.h>
#define MAXN 600002
using namespace std;

int N;

vector<pair<int,int>> v;
int ps[MAXN] = {0};
int cover[MAXN] = {0};

int getStreakSize(int l){
    int val = cover[l];
    int count = 1;
    for(int i = l - 1; i >= 0; i --){
        if(cover[i] != val) break;
        count += 1;
    }
    for(int i = l + 1; i < MAXN; i ++){
        if(cover[i] != val) break;
        count += 1;
    }
    return count;
}

int getSegmentsNotCovering(int i){
    for(int i = 0; i < N; i ++){
        if(!(v[i].first <= i && i <= v[i].second)){
            return i;
        }
    }
}

int getStreak(int startNPos){
    int streak = 1;
    int val = cover[startNPos];
    for(int i = startNPos - 1; i >= 0; i --){
        if(cover[i] != val) break;
        streak += 1;
    }
    for(int i = startNPos + 1; i < MAXN; i ++){
        if(cover[i] != val) break;
        streak += 1;
    }
    return streak;
}

int getStreak2(int startNPos){
    return -1; // streak;
}

void solve(){
    cin >> N;
    for(int i = 0; i < N; i ++){
        int a, b;
        cin >> a >> b;
        ps[a] += 1;
        ps[b + 1] -= 1;
        v.push_back(make_pair(a,b));
    }
    cover[0] = ps[0];
    for(int i = 1; i < MAXN; i ++){
        cover[i] = ps[i] + cover[i - 1];
    }
    /*for(int i = 0; i < 25; i ++){
        cout << cover[i] << " ";
    }
    cout << endl;
    */
    vector<pair<int,int>> streak;

    for(int i = 0; i < MAXN; i ++){
        if(cover[i] == N - 1 && cover[i + 1] == N){
            // Get responsible segments
            int toRemove = getSegmentsNotCovering(i);
            int orig = getStreakSize(i + 1);
            int add = getStreakSize(i);
        }else if(cover[i] == N && cover[i + 1] == N - 1){
            // Get responsible segments
            int toRemove = getSegmentsNotCovering(i + 1);
            int orig = getStreakSize(i);
            int add = getStreakSize(i + 1);
        }
        
    }
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
