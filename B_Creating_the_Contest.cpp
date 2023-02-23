#include <bits/stdc++.h> 
using namespace std; 
  
int N; 
int arr[200069]; 
int endedAt = 0;

int greedy(int start){
    int lastPicked = start;
    int out = 1;
    endedAt = start + 1;

    for(int i = start + 1; i < N; i ++){
        if(arr[lastPicked] < arr[i] && arr[i] <= 2 * arr[lastPicked]){
            lastPicked = i;
            endedAt = i + 1;
            out ++;
        }else{
            endedAt = i; 
            break;
        }
    }
    return out;
}

int main() { 
    cin >> N; 
    int best = 0;
    for(int i = 0; i < N; i ++){ 
        cin >> arr[i]; 
    }
    while(endedAt < N){
        int out = greedy(endedAt);
        // cout << endedAt << " out: " << out << endl;
        best = max(best, out);
    }
    cout << best << endl;
}    