#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int N;
int best = 0;
vector<pair<int,int>> a;
vector<pair<int,int>> b;
vector<pair<int,int>> c;

void check(vector<pair<int,int>>& a1,vector<pair<int,int>>& b1,vector<pair<int,int>>& c1){
    auto p1 = *(a1.end() - 1);
    int total = p1.first;
    pair<int,int> p2;
    for(auto iter = b1.rbegin(); iter < b1.rend(); iter ++){
        p2 = *iter;
        if(p2.second != p1.second){
            // require diff day
            total += p2.first;
            break;
        }
    }
    pair<int,int> p3;
    for(auto iter = c1.rbegin(); iter < c1.rend(); iter ++){
        p3 = *iter;
        if(p2.second != p3.second && p1.second != p3.second){
            // require diff day
            total += p3.first;
            break;
        }
    }
    best = max(total, best);
}

void solve(){
    cin >> N;
    best = 0; // reset
    // read input
    a.clear();
    b.clear();
    c.clear();
    for(int i = 0; i < N; i ++){
        pair<int,int> p;
        cin >> p.first;
        p.second = i;
        a.push_back(p);
    }
    for(int i = 0; i < N; i ++){
        pair<int,int> p;
        cin >> p.first;
        p.second = i;
        b.push_back(p);
    }
    for(int i = 0; i < N; i ++){
        pair<int,int> p;
        cin >> p.first;
        p.second = i;
        c.push_back(p);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    check(a,b,c);
    check(a,c,b);
    check(b,a,c);
    check(b,c,a);
    check(c,a,b);
    check(c,b,a);
    cout << best << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}