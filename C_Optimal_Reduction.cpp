#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int arr[MAXN] = {0};
int arrSorted[MAXN] = {0};

void solve(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    memcpy(arrSorted, arr, N * sizeof(int));
    sort(arrSorted, arrSorted + N);
    long long optimal = arrSorted[0];
    long long original = arr[0];
    for(int i = 0; i < N - 1; i ++){
        if(arrSorted[i] < arrSorted[i + 1]) optimal += arrSorted[i + 1] - arrSorted[i];
        if(arr[i] < arr[i + 1]) original += arr[i + 1] - arr[i];
    }
    // cout << original << " " << optimal << endl;
    if(original > optimal){
        cout << "NO";
    }else{
        cout << "YES";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int NN;
    cin >> NN;
    while(NN --) solve();
    return 0;
}
