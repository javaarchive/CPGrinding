#include <bits/stdc++.h>
#define MAXN 200002
#define ISDEBUG false
using namespace std;

int arr[MAXN];

int addMod10(int a){
    return a + a % 10;
}

int addMod10AForceCycle(int a){
    return addMod10AForceCycle(addMod10AForceCycle(addMod10AForceCycle(addMod10AForceCycle(a))));
}

int commonFormat(int start){
    if(start % 10 == 0){
        return start;
    }
    if(start % 10 == 5){
        return addMod10(start);
    }
    int v = start;
    while(v % 10 != 2 || v <= 60){
        v = addMod10(v);
        // cout << " v " << v << endl;
    }
    return v;
}

int classify(int v){
    int moddable = commonFormat(v);
    if(moddable % 10 == 0){
        return -1 * moddable/10;
    }
    return moddable % 20;
}

void solve(){
    int N;
    // cout << "READ N" << endl;
    cin >> N;
    // cout << "READ VALS" << endl;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    // cout << "READ VALS DONE" << endl;
    bool varying = false;
    // cout << "A";
    // cout << "CLA " << arr[0] << endl;
    int prev = classify(arr[0]);
    if(ISDEBUG) cout << "CLASSIFY INIT " << arr[0] << " " << prev << endl;
    // cout << "CLA DONE, BEGIN LOOP " << endl;
    // cout << "B";   
    for(int i = 1; i < N; i ++){
        // cout << "!";
        // cout << "CLASSIFY " << arr[i] << endl;
        int next = classify(arr[i]);
        if(ISDEBUG) cout << "CLASSIFY " << arr[i] << " " << next << endl;
        // cout << "CLA DONE " << endl;
        // cout << "?";
        if(prev != next){
            varying = true;
            break;
        }
        prev = next;
    }
    // cout << "C";
    if(varying){
        cout << "No";
    }else{
        cout << "Yes";
    }
    cout << endl;
    // cout << "BYE" << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --){
        // cout << "START " << NN << endl;
        solve();
        // cout << "END " << NN << endl;
    }
    return 0;
}
