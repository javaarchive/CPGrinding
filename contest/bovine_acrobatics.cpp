#include <bits/stdc++.h>
using namespace std;

int N, M, K;

set<int> weightKinds;
unordered_map<int,int> freq;

void solve(){
    cin >> N >> M >> K;
    long long total = 0;
    for(int i = 0; i < N; i ++){
        int w, wfreq;
        cin >> w >> wfreq;
        freq[w] = wfreq;
        weightKinds.insert(w);
        total =+ ((long long) wfreq);
    }
    // attempt greedy
    int ans = 0;
    int towersCreated = 0;
    vector<int> chain;
    chain.reserve(N);
    long long cowsUsed = 0;
    while(towersCreated < M){
        int minWeightRequirement = 0;
        int chainMin = INT32_MAX;
        chain.clear();

        while(weightKinds.lower_bound(minWeightRequirement) != weightKinds.end()){
            auto ref = weightKinds.lower_bound(minWeightRequirement);
            int nextWeight = *ref;
            chainMin = min(chainMin, freq[nextWeight]);
            chain.push_back(nextWeight);
            minWeightRequirement = nextWeight + K;
        }

        // cout << "formed a chain of size " << chain.size() << endl;

        int needed = M - towersCreated;
        chainMin = min(chainMin, needed);

        if(chain.empty()){
            break;
        }

        // cout << "x" << chainMin << " ";
        for(auto weightInChain: chain){
            // cout << " " << weightInChain;
            freq[weightInChain] -= chainMin;
            if(freq[weightInChain] == 0){
                weightKinds.erase(weightInChain);
            }
        }
        // cout << endl;

        cowsUsed += chain.size() * chainMin;
        towersCreated += chainMin;
    }

    cout << cowsUsed << endl;
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}