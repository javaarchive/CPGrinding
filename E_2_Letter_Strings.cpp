#include <bits/stdc++.h>
#define MAXN 100009

using namespace std;

map<char,multiset<char>> oneTwo;
map<char,multiset<char>> twoOne;

map<string,long long> counter;

string strings[MAXN];

void solve(){
    int N = 0;
    cin >> N;
    twoOne.clear();
    oneTwo.clear();
    counter.clear();
    for(int i = 0; i < N; i ++){
        cin >> strings[i];
        // map first to second
        oneTwo[strings[i][0]].insert(strings[i][1]);
        // map second to first
        twoOne[strings[i][1]].insert(strings[i][0]);

        counter[strings[i]] += 1;
    }
    long long ans = 0;
    for(int i = 0; i < N; i ++){
        char a = strings[i][0];
        char b = strings[i][1];
        // cout << oneTwo[a].size() << " + " << twoOne[b].size() << " - " << counter[strings[i]] << endl;
        long long A = oneTwo[a].size() - counter[strings[i]]; // sub self
        long long B = twoOne[b].size() - counter[strings[i]]; // sub self
        // cout << "Prefix with " << a << " " << A << endl;
        // cout << "Suffix with " << b << " " << B << endl;
        // cout << a << b << endl;
        // cout << A << " + " << B << " = " << (A + B) << endl;
        ans += A;
        ans += B;
    }
    // cout << "PREANS " << ans << endl;
    // ans = ans/2;
    ans = ans / 2;
    cout << ans << endl;
    return;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --){
        solve();
    }
    return 0;
}
