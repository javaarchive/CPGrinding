#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
// 2^30 - 1
#define LIMIT 1073741823
// 2^31 - 1
// #define LIMIT 2147483647

int myrand_scuffed(){
    // this is scuffed
    return ((rand() % LIMIT) + ((rand() % LIMIT) ) + ((rand() % LIMIT)) + (rand() % LIMIT) + ((rand() % LIMIT) ) + ((rand() % LIMIT)) + (rand() % LIMIT) + ((rand() % LIMIT) ) + ((rand() % LIMIT)) + (rand() % LIMIT) + ((rand() % LIMIT) ) + ((rand() % LIMIT)) + (rand() % LIMIT) + ((rand() % LIMIT) ) + ((rand() % LIMIT)) + (rand() % LIMIT) + ((rand() % LIMIT) ) + ((rand() % LIMIT)) + (rand() % LIMIT) + ((rand() % LIMIT) ) + ((rand() % LIMIT)) ) % LIMIT;
}

// actually works properly
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int myrand(){
    return rng() % LIMIT;
}



unordered_set<int> seen;
int rand_gen_unique(){
    int r = myrand();
    // keep regening if we have already seen
    while(seen.find(r) != seen.end() || r <= 5){
        r = myrand();
    }
    // cout << "Ins " << r << endl;
    seen.insert(r);
    return r;
}

int A[MAXN];
int B[MAXN];

int N;

int fastQuickPow2(int p){
    return 1 << p;
}

void solve(){
    cin >> N;
    bool printExtra = false;
    int aCount = N/2; // indexes 0 1 2 ... N/2-1
    int bCount = N/2;
    if(N % 2 == 1){
        printExtra = true;
        A[N/2] = -1; // print extra
        aCount ++;
    }

    int aXOR = 0;
    for(int i = 0; i < aCount - 1; i ++){
        int next = rand_gen_unique();
        A[i] = next;
        aXOR ^= next;
    }
    int bXOR = 0;
    for(int i = 0; i < bCount - 1; i ++){
        int next = rand_gen_unique();
        B[i] = next;
        bXOR ^= next;
    }
    // for(int i = 0; i < N; i ++){
    while(true){
        int target = rand_gen_unique();
        // cout << "Our target " << target << endl;
        int lastA = aXOR ^ target;
        int lastB = bXOR ^ target;
        // cout << "la " << lastA << " lb " << lastB << endl;
        if(lastA == lastB){
            // cout << "a " << endl;
            continue;
        }
        // should not be able to find lastA and lastB as already generated
        if((seen.find(lastA) == seen.end() && seen.find(lastB) == seen.end()) || (N < 4)){ // N < 6 hack, so aXOR and bXOR arent't 0
            A[aCount - 1] = lastA;
            B[bCount - 1] = lastB;
            break;
        }else{
            /*cout << "Oops ";
            if(seen.find(lastA) != seen.end()){
                cout << "A" << lastA << endl;
            }
            if(seen.find(lastB) != seen.end()){
                cout << "B" << lastB << endl;
            }
            string stop;
            cin >> stop;*/
        }
    }

    // Print it out
    for(int i = 0; i < N/2; i ++){
        cout << A[i] << " ";
        cout << B[i] << " ";
    }
    if(printExtra){
        cout << A[N / 2];
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    srand (time(NULL));
    int NN;
    // cout << "RAND_MAX " << RAND_MAX << endl;
    cin >> NN;
    while(NN --){
        solve();
        // less rng work
        seen.clear();
    }
    return 0;
}
