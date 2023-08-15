#include <bits/stdc++.h>

using namespace std;

int N,Q;
set<int> shields;

int T = 1;

int get_shield_at_or_before(int pos){
    auto it = shields.lower_bound(pos);
    if(it == shields.end()) return -1;
    if(*it == pos){
        return pos;
    }
    if(it == shields.begin()) return -1;
    it --;
    return *it;
}

long long calc(){
    long long ans = 0;
    long long pos = 0;

    while(pos < N){
        if((N - pos) <= T){
            // done we are there
            return ans + (N - pos);
        }
        int shield = get_shield_at_or_before(pos + T);
        if(shield == -1 || shield == pos){
            // not possible
            return -1;
        }else{
            pos = shield;
            ans += T;
        }
    }

    return ans;
}

void solve(){
    cin >> N >> Q;
    int shieldPosition;
    for(int i = 0; i < Q; i ++){
        T = i + 1;
        cin >> shieldPosition;
        shields.insert(shieldPosition);
        cout << calc() << endl;
    }
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
