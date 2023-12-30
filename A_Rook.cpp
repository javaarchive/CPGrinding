#include <bits/stdc++.h>

using namespace std;

int intify(char c){
    return c - 'a';
}

int indexify(int pos){
    return pos - 1;
}

void solve(){
    string line;
    cin >> line;
    int col = intify(line[0]);
    int row = indexify(line[1] - '0');
    // cout << col << " " << row << endl;
    for(int i = 0; i < 8; i ++){
        if(i == row){ // vary row
            continue;
        }
        cout << line[0] << (i + 1) << endl;
    }
    for(int i = 0; i < 8; i ++){
        if(i == col){ // vary row
            continue;
        }
        cout << ((char) (i+'a')) << line[1] << endl;
    }
}


int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i ++){
        solve();
    }
    return 0;
}
