#include <bits/stdc++.h>
#define MAXN 51
using namespace std;

int NN,N;
unordered_map<int,char> mapping; 

int nums[MAXN];
char chars[MAXN];

void solve(){
    mapping.clear();
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> nums[i];
    }
    string s;
    cin >> s;
    for(int i = 0; i < N; i ++){
        chars[i] = s[i];
    }
    for(int i = 0; i < N; i ++){
        int from = nums[i];
        char to = chars[i];
        if(mapping.find(from) == mapping.end()){
            mapping[from] = to;
            // cout << from << " " << to << endl;
        }else{
            if(mapping[from] != to){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    cin >> NN;
    while(NN --){
        solve();
    }
    return 0;
}
