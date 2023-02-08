#include <bits/stdc++.h>
using namespace std;
#define MAXT 11
#define MAXN 100002

string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

set<pair<char,char>> cycles;
set<pair<char,char>> edges;
map<char, vector<char>> charEdgesMap;

set<char> usedInitialLetters;

int N, L;
string a;
string b;

int uniqTransforms;

set<char> cycleCheckVisited;

void solve(){
    cycles.clear();
    edges.clear();
    charEdgesMap.clear();
    usedInitialLetters.clear();

    uniqTransforms = 0;
    cycleCheckVisited.clear();

    cin >> a;
    cin >> b;
    L = a.length();

    for(int i = 0; i < L; i ++){
        pair<char,char> p = make_pair(a[i],b[i]);
        if(edges.find(p) == edges.end()){
            // first time we see an edge
            edges.insert(p);
            charEdgesMap[a[i]].push_back(b[i]);
            usedInitialLetters.insert(a[i]);
            usedInitialLetters.insert(b[i]);
            if(a[i] != b[i]){
                // cout << "Uniq " << a[i] << b[i] << endl;
                uniqTransforms ++;
            }
        }
    }
    for(int i = 0; i < charset.length(); i ++){
        char c = charset[i];
        if(charEdgesMap[c].size() > 1){
            // No, a letter cannot wish to become two things
            cout << -1 << endl;
            return;
        }
    }

    int ops = uniqTransforms;
    // every cycle needs a temporarry letter for reserve
    int usableTemporaryLetters = charset.length() - usedInitialLetters.size();
    int MAX_CYCLE_LENGTH = charset.length();
    // Now we persue the cycles
    for(char startLetter: charset){
        if(cycleCheckVisited.count(startLetter)) continue;
        char cur = startLetter;
        // Skip dead end
        if(charEdgesMap[startLetter].size() == 0){
            // No cycle
            continue;
        }
        // Loop!
        if(charEdgesMap[startLetter].size() == 1 && charEdgesMap[startLetter][0] == startLetter){
            continue;
        }
        for(int i = 0; i < MAX_CYCLE_LENGTH; i ++){
            /*if(cycleCheckVisited.count(cur)){
                break;
            }*/
            if(charEdgesMap[cur].size() == 0){
                // dead end
                break;
            }
            char nextl = charEdgesMap[cur][0];
            // Loop!
            /*if(nextl == startLetter && i == 1){
                break;
            }*/
            if(nextl == startLetter && i != 0){
                // Cycle found
                // cout << nextl << " Cycle " << endl;
                // quickly go around again marking each as visited
                cycleCheckVisited.insert(nextl);
                char cur2 = nextl;
                for(int j = 0; j < MAX_CYCLE_LENGTH; j ++){
                    cur2 = charEdgesMap[cur2][0];
                    cycleCheckVisited.insert(cur2);
                    if(cur2 == nextl) break;
                }

                ops ++ ;
                // require at least one ig. 
                if(usableTemporaryLetters <= 0){
                    // not enough
                    cout << -1 << endl;
                    return;
                }
                // usableTemporaryLetters --;
                break;
            }
            cur = nextl;
        }
    }
    /*if(usableTemporaryLetters < 0){
        // not enough
        // cout << -1 << endl;
        return;
    }*/

    cout << ops << endl; 
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
