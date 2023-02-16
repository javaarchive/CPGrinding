#include <bits/stdc++.h>
#define MAXN 101
using namespace std;

int N;
char tstring[MAXN];
char target[MAXN];

map<char, int> sanity;
map<char, int> sanity2;

vector<int> output;

bool checkDone(){
    for(int i = 0; i < N; i ++){
        if(tstring[i] != target[i]) return false;
    }
    return true;
}

void move(int i, int j){
    // move j down to i
    for(int k = j; k > i; k --){
        output.push_back(k);
        swap(tstring[k], tstring[k - 1]);
    }
}

void solve(){
    cin >> N;
    cin >> tstring;
    cin >> target;
    for(int i = 0; i < N; i ++) sanity[tstring[i]] += 1;
    for(int i = 0; i < N; i ++) sanity2[target[i]] += 1;
    // Frequency match check
    for(int i = 0; i < N; i ++){
        if(sanity[tstring[i]] != sanity2[tstring[i]]){
            cout << -1 << endl;
            return;
        }
    }
    for(int i = 0; i < N; i ++){
        if(sanity[target[i]] != sanity2[target[i]]){
            cout << -1 << endl;
            return;
        }
    }
    while(!checkDone()){
        for(int i = 0; i < N; i ++){
            if(tstring[i] != target[i]){
                // oh no not equal, go grab something from above
                // cout << "We need a " << target[i] << " at " << i << endl;
                for(int j = i + 1; j < N; j ++){
                    if(tstring[j] == target[i]){
                        // found it
                        // cout << " move " << i << " " << j << endl;
                        move(i, j);
                        break;
                    }
                }
                // cout << "CURRENT " << endl;
                // for(int l = 0; l < N; l ++) cout << tstring[l];
                // cout << endl;              
            }
        }
    }
    cout << output.size() << endl;
    for(int i = 0; i < output.size(); i ++){
        cout << output[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
