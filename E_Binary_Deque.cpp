#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int N, S;
int arr[MAXN];
int ps[MAXN];
int query(int start, int end){
    return ps[end + 1] - ps[start];
}
void solve(){
    cin >> N >> S;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
        ps[i + 1] = 0;
    }
    // cout << "OK!" << endl;
    ps[0] = 0;
    // build ps
    for(int j = 0; j < N; j ++){
        ps[j + 1] = ps[j] + arr[j];
    }

    // cout << "OK " << endl;
    /*
    function binary_search(A, n, T) is
    L := 0
    R := n − 1
    while L ≤ R do
        m := floor((L + R) / 2)
        if A[m] < T then
            L := m + 1
        else if A[m] > T then
            R := m − 1
        else:
            return m
    return unsuccessful
    */
   int best = INT32_MAX;
   int loops = 0;
   for(int s = 0; s < N; s ++){
        int L = s;
        int R = N - 1;
       
        while(L <= R){
            loops ++;
            int e = floor((L + R) / 2);
            // cout << L << " " << e << " " << R << endl;
            int v = query(s,e);
            if(loops > 1000){
                cout << L << " " << e << " " << R << endl;
                cout << "V: " << v << " s " << s<< " e " << e << endl;
                break;
            }
            if(v < S){
                L = v + 1;
            }else if(v > S){
                R = v - 1;
            }else{
                int cost = (s-1) + ((N - 1) - (v + 1) + 1);
                best = min(best, cost);
                break;
            }
        }
        // no change ig
   }
   if(best = INT32_MAX) best = -1;
   cout << best << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    // cout << "AGH" << endl;
    while(T --) solve();    
    return 0;
}
