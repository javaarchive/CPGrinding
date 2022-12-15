#include <bits/stdc++.h>
#define MAXN 2002

using namespace std;

int target[MAXN];
int buffer[MAXN];
int N;

map<int,int> invIndex;

int shift = 0;

int shiftCounts[MAXN] = {0};

int indexOf(int val){
    for(int i = 0; i < N; i ++){
        if(target[i] == val){
            return i;
        }
    }
    return -1;
}

void turn(int range, int amount){
    for(int i = 0; i < range; i ++){
        // ex; if range = 1, then 0 -> 0
        buffer[i] = target[(range + i + amount ) % range];
    }
    for(int i = 0; i < range; i ++){
        target[i] = buffer[i];
    }
}

int cyclDist(int bound, int a, int b){
    if(b >= a){
        return b - a;
    }else{
        // b < a
        //      dist before cycle inclusive of cycle + distance after cycle
        return (bound - a) + b; 
    }
}

void solve(){
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> target[i];
        // invIndex[target[i]] = i;
        shiftCounts[i] = 0;
        buffer[i] = -1;
    }
    shiftCounts[N] = 0;
    for(int i = N; i > 0; i --){
        int start = indexOf(i);
        int ending = i - 1;
        int dist = cyclDist(i, ending, start);
        shiftCounts[i - 1] = dist;
        turn(i, dist);
    }
    // Flatten shiftCounts

    /*for(int i = 0; i < N; i ++){
        cout << target[i] << " ";
    }
    cout << endl;*/
    for(int i = 0; i < N; i ++){
        cout << shiftCounts[i] << " ";
    }
    cout << endl;
}


void test(){
    target[0] = 1;
    target[1] = 2;
    target[2] = 3;
    target[3] = 4;
    target[4] = 5;
    target[5] = 6;
    N = 6;
    for(int i = 0; i < N; i ++){
        cout << target[i] << " ";
    }
    cout << endl;
    turn(3,1);
    for(int i = 0; i < N; i ++){
        cout << target[i] << " ";
    }
    
    cout << endl;
    target[0] = 1;
    target[1] = 2;
    target[2] = 3;
    target[3] = 4;
    target[4] = 5;
    target[5] = 6;

    turn(3,2);
    for(int i = 0; i < N; i ++){
        cout << target[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    // test();
    int T;
    cin >> T;
    for(int i = 0; i < T; i ++){
        solve();
    }
    return 0;
}