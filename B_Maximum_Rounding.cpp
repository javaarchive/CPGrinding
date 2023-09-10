#include <bits/stdc++.h>
#define MAXL 200002
using namespace std;

int L;
int num[MAXL] = {' '};

void solve(){
    string temp;
    cin >> temp;
    L = temp.size();
    for(int i = 0; i < L; i ++){
        num[i] = (int) (temp[i] - '0');
    }
    // self-note: numbers are strings so we can handle huge af stuff
    int carry = 0;
    int zPoint = INT32_MAX;
    for(int i = L - 1; i >= 0; i --){
        bool roundUp = false;
        if(num[i] >= 5){
            num[i] = 0;
            roundUp = true;
        }
        if(carry > 0){
            int startingDigit = num[i];
            int sum = startingDigit + carry; 
            int remainder = sum % 10;
            int nextCarry = sum / 10;
            carry = nextCarry;
            num[i] = remainder;
        }
        if(num[i] >= 5){
            num[i] = 0;
            roundUp = true;
        }
        if(roundUp){
            zPoint = i;
            carry ++;
        }
        
    }
    if(carry > 0){
        cout << carry;
    }
    for(int i = 0; i < L; i ++){
        if(zPoint <= i){
            cout << 0;
            continue;
        }
        cout << num[i];
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    fill(num, num + MAXL, -1);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}