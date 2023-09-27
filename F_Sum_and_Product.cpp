#include <bits/stdc++.h>
#define int long long int
using namespace std;

int N,Q;
map<int,long long> freq;

// ex. 2,3 x=5 y=6
// 25

 // a + b = x
// ab = y
// ->
// b = x - a
// a(x - a) = y
// ax - a^2 - y = 0
// -a^2 + xa - y = 0
// a^2 - xa + y = 0
//     x +- sqrt(x^2 - 4y)
// a = -------------
//           2

pair<int,int> null_pair = make_pair(-69424269, -69133769);

pair<int,int> solve_sp(long long sum, long long product){
    // x = sum
    // y = product
    if((sum * sum - 4 * product) < 0LL){
        return null_pair;
    }
    long long discrim = sqrtl(sum * sum - 4 * product);
    long long a = (sum - discrim)/2;
    long long b = (sum + discrim)/2;
    // sanity
    if((a + b) != sum){
        return null_pair;
    }
    if((a * b) != product){
        return null_pair;
    }
    return make_pair(a,b); // cast!
}

bool is_null_pair(pair<int,int> inp){
    return null_pair.first == inp.first && null_pair.second == inp.second;
}

void solve(){
    cin >> N;
    freq.clear();
    for(int i = 0; i < N; i ++){
        int v;
        cin >> v;
        freq[v] ++;
    }
    cin >> Q;
    int x, y;
    for(int i = 0; i < Q; i ++){
        cin >> x >> y;
        pair<int,int> sol = solve_sp(x,y);
        if(is_null_pair(sol)){
            cout << 0 << " ";
            continue;
        }
        // cout << "The numbers that sum to " << x << " and multiply to " << y << endl;
        // cout << " are " << sol.first << "," << sol.second << endl;
        bool identical = sol.first == sol.second;
        if(identical){
            long long f = freq[sol.first];
            // cout << " id freq " << f << endl;
            cout << (f * (f - 1))/2 << " ";
        }else{
            cout << freq[sol.first] * freq[sol.second] << " ";
        }
    }
    cout << endl;
}



int32_t main(int32_t argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}