#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int N;

struct Friend {
    int foodCost,balance;
    int diff;
};

Friend friends[MAXN];

void solve(){
    deque<Friend> negative;
    deque<Friend> zeros;
    deque<Friend> positive;
    cin >> N;
    long long totalDiff = 0;
    for(int i = 0; i < N; i ++){
        cin >> friends[i].foodCost;
    }
    for(int i = 0; i < N; i ++){
        cin >> friends[i].balance;
        friends[i].diff = friends[i].balance - friends[i].foodCost;
        totalDiff += friends[i].diff;
    }
    sort(friends, friends + N,[](Friend a, Friend b) {return a.diff < b.diff; });
    for(int i = 0; i < N; i ++){
        Friend f = friends[i];
        if(f.diff == 0){
            zeros.push_back(f);
        }else if(f.diff < 0){
            negative.push_back(f);
        }else if(f.diff > 0){
            positive.push_back(f);
        }
    }

    /*if(totalDiff == 0LL){
        cout << 1 << endl;
        return;
    }*/

    long long best = 0LL;
    while(zeros.size() >= 2){
        // cout << "ADD Z " << endl;
        best ++;
        zeros.pop_back();
        zeros.pop_back();
    }
    // cout << "Init " << negative.size() << " " << positive.size() << endl;
    while(!negative.empty()){
        long long balance = negative.front().diff;
        negative.pop_front();
        // cout << balance << "  ";
        // cout << "initial " << balance;
        if(!positive.empty()){
            if(balance >= 0LL) break;
            int add = positive.back().diff;
            // cout << "+" << add;
            if((balance + add) >= 0){
                // cout << "Pair " << balance << " with " << add << endl;
                positive.pop_back();
            }else{
                // cout << "Pair fail " << balance << " with " << add << endl;
            }
            balance += add;
        }
        // cout << endl;
        // cout << " new " << balance << endl;
        if(balance < 0LL){
            continue;
        }
        // cout << "BEST += 1" << endl;
        best ++;
    }
    // we can pair these up
    // cout << "Positive += " << (floor(positive.size() / 2)) << endl;
    best += floor(positive.size()/2);
    if(positive.size() % 2 == 1 && zeros.size() == 1){
        best ++;
    }
    cout << best << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
