#include <bits/stdc++.h>
using namespace std;

int N;
string s;
map<char, int> freq;
map<char, int> freq_pair;

void solve(){
    cin >> N;
    cin >> s;
    freq.clear();
    freq_pair.clear();
    if(N % 2 == 1){
        cout << -1 << endl;
        return;
    }
    int H = N/2; // half
    for(int i = 0; i < N; i ++){
        freq[s[i]] ++;
    }
    for(char c = 'a'; c <= 'z'; c ++){
        if(freq[c] > H){ // where H is half N
            cout << -1 << endl; // pigeonhole
            return;
        }
    }

    int asymmetric_pairs = 0;

    for(int i = 0; i < H; i ++){
        int j = N - 1 - i;
        if(s[i] == s[j]){
            freq_pair[s[i]] ++;
        }else{
            asymmetric_pairs ++;
        }
    }

    long long pairingCount = 0;

    vector<pair<int,char>> pairings;
    for(char c = 'a'; c <= 'z'; c ++){
        if(freq_pair[c] > 0){
            pairingCount += freq_pair[c];
            pairings.push_back(make_pair(freq_pair[c],c));
        }
    }
    sort(pairings.begin(), pairings.end());
    reverse(pairings.begin(), pairings.end()); // largest first

    long long ans = 0;

    if(pairings.empty()){
        cout << 0 << endl;
        return;
    }

    int largestPairingSize = pairings[0].first;

    // if one piece is larger than every other
    if((pairingCount - largestPairingSize) < largestPairingSize){
        int inoptimal = 2 * largestPairingSize - pairingCount;
        // cout << "R: ";
        ans = largestPairingSize;
    }else{
        ans = pairingCount/2 + pairingCount % 2;
    }

    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}