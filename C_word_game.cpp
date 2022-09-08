#include <bits/stdc++.h>

using namespace std;
void solve(){
    int N;
    cin >> N;
    map<string,int> whoChose;
    set<string> words; // tree struct
    for(int player = 0; player < 3; player ++){
        for(int i = 0; i < N; i ++){
            string word;
            cin >> word;
            whoChose[word] += 1 << player; 
            words.insert(word);
        }
    }

    int a = 0,b = 0,c = 0;

    for(string word: words){
        int chooseNum = whoChose[word];
        int binaryDecode = chooseNum;
        // cout << "BDC " <<  binaryDecode << endl;
        bool aChose = false;
        bool bChose = false;
        bool cChose = false;
        if(binaryDecode >= 4){
            binaryDecode -= 4;
            cChose = true;
        }
        if(binaryDecode >= 2){
            binaryDecode -= 2;
            bChose = true;
        }
        // cout << "Last part " << binaryDecode << endl;
        if(binaryDecode >= 1){
            binaryDecode -= 1;
            aChose = true;
        }
        int sum = aChose + bChose + cChose;
        if(sum == 2){
            if(aChose){a += 1;}
            if(bChose){b += 1;}
            if(cChose){c += 1;}
        }else if(sum == 1){
            if(aChose){a += 3;}
            if(bChose){b += 3;}
            if(cChose){c += 3;}
        }
    }

    cout << a << " " << b << " " << c << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
