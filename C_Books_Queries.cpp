#include <bits/stdc++.h>

using namespace std;

int Q;

map<int, int> pos;
int leftInsx = -1;
int rightInsx = 0;

void solve(){
    cin >> Q;
    for(int i = 0; i < Q; i++){
        char c;
        int id;
        cin >> c >> id;
        if(c == 'L'){
            pos[id] = leftInsx;
            leftInsx --;
        }else if(c == 'R'){
            pos[id] = rightInsx;
            rightInsx ++;
        }else if(c == '?'){
            cout << min((pos[id] - leftInsx) - 1, (rightInsx - pos[id]) - 1) << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
