#include <iostream>
using namespace std;
int N;
//            a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
int types[] = {1,0,0,0,1,0,0,0,1,2,2,2,2,2,1,2,0,0,2,2,1,0,2,0,0,0};
string solve(string W) {
    N = W.size();
    // invalid char
    for(int i = 0; i < N; i++) if(types[W[i] - 'a'] == 0) return "ike"; 
    for(int i = 0; i < N - 1; i ++){
        int ca = W[i];
        int cb = W[i + 1];
        int ta = types[ca - 'a'];
        int tb = types[cb - 'a'];
        if(tb == 1 && ta == 1){
            return "ike";
        }
        if(ca == 'w' && cb == 'u') return "ike";
        if(ca == 'w' && cb == 'o') return "ike";
        if(ca == 'j' && cb == 'i') return "ike";
        if(ca == 't' && cb == 'i') return "ike";
        if(ca == 'n' && cb == 'n') return "ike";
        if(ca == 'n' && cb == 'm') return "ike";
        if(ta == tb && ta == 2 && ca != 'n') return "ike";
    }
    if(W[N - 1] == 'n' && N == 1) return "ike";
    if(W[N - 1] == 'n' && types[W[N - 2] - 'a'] == 2) return "ike";
    if(types[W[N - 1]-'a'] == 2 && W[N - 1] != 'n'){
        return "ike"; // illegal end
    }
    return "pona";
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string W;
        cin >> W;
        cout << solve(W) << endl;
    }
}
