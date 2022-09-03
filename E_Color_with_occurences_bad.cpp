#include <bits/stdc++.h>
#define MAXT 101

using namespace std;

int N, T;
string str;
void solve(){
    cin >> str;
    T = str.length();
    cin >> N;
    vector<string> substrs;
    //          substr id  pos
    vector<pair<int       ,   int>> choices;
    for(int i = 0; i < N; i ++){
        string substr;
        cin >> substr;
        int K = substr.length();
        substrs.push_back(substr);
        // quick dumb match
        // TODO: if not lazy add KMP saves 10 complexity
        for(int j = 0; j < T - K + 1; j ++){
            bool works = true;
            for(int k = 0; k < K; k ++){
                if(str[j + k] != substr[k]){
                    works = false;
                    break;
                }
            }
            if(works){
                // cout << substr << " matched at " << j << endl;
                choices.push_back(make_pair(i,j));
            }
        }
    }

    int total = 0;
    bool colored[MAXT] = {0};

    int ans = 0;
    vector<pair<int,int>> ansReason;

    // order not really matter
    while(true){
        bool hasGood = false;

        int newlyCovered = 0;
        int newColoringSpecifacation = -1;

        for(int i = 0; i < choices.size(); i ++){
            int covered = 0;
            int subi = choices[i].first;
            int pos = choices[i].second;
            int K = substrs[subi].length();
            // run it against our current fillings
            // if we picked this hypothetically how much fillings do we gain
            for(int i = pos; i < pos + K; i ++){
                covered += colored[i] ? 0 : 1;
            }
            if(covered > newlyCovered){
                newlyCovered = covered;
                newColoringSpecifacation = i;
            }
        }

        hasGood = newlyCovered > 0;
        // if we can't do anything then sad
        if(!hasGood){
            // cout << "No more good choices :( " << endl;
            // goto "sob!"
            break;
        }

        int subi = choices[newColoringSpecifacation].first;
        int pos = choices[newColoringSpecifacation].second;
        int K = substrs[subi].length();
        
        // cout << "Picked " << subi << " aka " << substrs[subi] << " running at " << pos << " ++ " << newlyCovered << endl;
        // cout << (subi + 1) << " " << (pos + 1) << endl;

        for(int i = pos; i < pos + K; i ++){
            colored[i] = 1;
        }
        
        ans ++;
        ansReason.push_back(make_pair(subi + 1, pos + 1));
        total += newlyCovered;
    }

    if(total != T){
        // sob!
        // cout << "Failed, we are lacking " << T - total << " only got " << total << endl;
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
    for(pair<int,int> outPair: ansReason){
        cout << outPair.first << " " << outPair.second << endl;
    }
    
    
}

// help

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --){
        solve();
    }
    return 0;
}