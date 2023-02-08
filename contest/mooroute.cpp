#include <bits/stdc++.h>
#define MAXN 100002
#define MAX2N 200005
using namespace std;

int N;

int target[MAX2N];
int reality[MAX2N];

int pos, dir;

bool checkRightOf(){
    for(int i = pos + 1; i <= 2 * N; i++){
        if(reality[i] != target[i]){
            return false;
        }
    }
    return true;
}

bool shouldKeepGoing(){
    if((pos + dir/2) < 0) return false; // out of bounds
    if((pos + dir/2) >= 2 * N) return false; // out of bounds
    int diff = target[pos + dir/2]  - reality[pos + dir/2];
    if(diff == 0) return false; // can't 
    if(diff == 1){
        // point of no return check 
        return checkRightOf();
    }
    // you can always come back
    return true;
    // return reality[pos + dir/2] < target[pos + dir/2] - 1;
}

bool meetsExpectations(){
    for(int i = 0; i < N; i++){
        if(reality[2*i + 1] != target[2*i + 1]){
            return false;
        }
    }
    return true;
}

void printStatus(){
    cout << "Pos: " << pos << " Dir: " << dir << endl;
    // Expectation
    for(int i = 0; i <= 2 * N; i ++){
        cout << target[i] << " ";
    }
    cout << endl;
    // Reality
    for(int i = 0; i <= 2 * N; i ++){
        cout << reality[i] << " ";
    }
    cout << endl;
}


// POV: desperate for performance 
char lookup[] = "LLLLRRRR";

char getDirChar(){
    return lookup[4 + dir];
}

int minTouches = INT32_MAX;
int shortcut; 

void solve(){
    fill(target,target + 2*N+2, 0);
    fill(reality,reality + 2*N+2, 0);
    cin >> N;
    for(int i = 0; i < N; i ++){
        int touches;
        cin >> touches;
        target[2*i + 1] = touches;
        minTouches = min(minTouches, touches);
    }
    // We predo a few complete back and forths
   
    /*shortcut = max((minTouches - minTouches % 2) - 4,0);

    // cout << "SHORTCUT " << shortcut << endl;

    string Lrepeat = string(N, 'L');
    string Rrepeat = string(N, 'R');

    for(int i = 0; i < shortcut; i ++){
        cout << Rrepeat;
        cout << Lrepeat;
    }

    for(int i = 1; i <= 2 * N; i += 2){
        target[i] -= shortcut;
    }*/

    pos = 0;
    dir = 2;
    while(true){
        if(shouldKeepGoing()){
            cout << getDirChar();
            int newPos = pos + dir;
            int betweenPos = pos + dir/2;
            reality[betweenPos] += 1;
            // Update state!
            pos = newPos;
        }else{
            dir = -dir;
            if(!shouldKeepGoing()){
                // cout << endl << "Change direction failed" << endl;
                // printStatus();
                break;
            }
        }
    }

    if(meetsExpectations()){
        cout << endl;
    }else if(pos == 0){
        // for(int i = 0; i < N; i ++) cout << "R";
        string Rrepeat = string(N, 'R');
        cout << Rrepeat << endl;   
    }else{
        // for(int i = 0; i < N; i ++) cout << "L";
        string Lrepeat = string(N, 'L');
        cout << Lrepeat << endl;
    }
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
