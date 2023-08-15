#include <bits/stdc++.h>
using namespace std;
#define MAXN 150002
#define MAXQ 150002

int N, Q;
long long origArr[MAXN];
long long arr[MAXN];

// finds index to **insert before**
int bsForInsertion(int val){
    int l = 0, r = N - 1;
    while(l < r){
        int mid = (l + r) / 2;
        // cerr << " bs: " << l << " " << mid << " " << r << endl;
        if(arr[mid] < val){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}

long long psTri[MAXN];
long long ps[MAXN];

map<int, vector<int>> instancesInOriginal;

// 0 1   2
// 0 a a+b

// 0 1 -> should return a+b
// 1 1 should return b

long long querySum(int aInclusive, int bInclusive){
    return ps[bInclusive + 1] - ps[aInclusive];
}
// same as above but queries triangle sum
long long queryTriangleSumNoProc(int aInclusive, int bInclusive){
    return psTri[bInclusive + 1] - psTri[aInclusive];
}
//  0  1  2  3  4  5  6  7  8   9
// 1a 2b 3c 4d 5e 6f 7g 8h 9i 10j
// say if we query 4 through 7
// we want  e + 2f + 3g + 4h
// from sum no proc we actually get 5e + 6f + 7g + 8h
// thus we subtract (aInclusive which is 4)*(querySum(aInclusive,bInclusive))


long long queryTriangleSum(int aInclusive, int bInclusive){
    long long sum = querySum(aInclusive, bInclusive);
    long long triangleSum = queryTriangleSumNoProc(aInclusive, bInclusive);
    return triangleSum - (sum * (aInclusive)); // see above explain
}

void buildPs(){
    ps[0] = 0;
    ps[1] = 0;
    for(int i = 0; i < N; i ++){
        ps[i + 1] = ps[i] + arr[i];
    }
    psTri[0] = 0;
    psTri[1] = 0;
    for(int i = 0; i < N; i ++){
        psTri[i + 1] = psTri[i] + (arr[i] * (i + 1)); // el i is actually index (i+1) so it multiplied by (i+1)
    }
}

void writeInstances(){
    instancesInOriginal.clear();
    for(int i = 0; i < N; i++){
        instancesInOriginal[arr[i]].push_back(i);
    }
}

void solve(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> origArr[i];
        arr[i] = origArr[i];
    }
    // optimize
    sort(arr, arr + N); 
    writeInstances();
    buildPs();
    long long normalTriangle = psTri[N];
    // cerr << "Read in queries " << endl;
    cin >> Q;
    for(int i = 0; i < Q; i ++){
        int index, newValue;
        cin >> index >> newValue;
        index --;
        int oldVal = origArr[index];
        int fromIndex = instancesInOriginal[oldVal][instancesInOriginal[oldVal].size() - 1];
        int toIndex = bsForInsertion(newValue);
        if(fromIndex < toIndex) toIndex --;
        // cerr << "From index " << fromIndex << " to index " << toIndex << " we replace " << oldVal << " with " << newValue << endl;
        if(fromIndex < toIndex){
            // oxxxx shift to
            // xxxxo
            long long mid = queryTriangleSumNoProc(fromIndex + 1, toIndex) - querySum(fromIndex + 1, toIndex); // lower it
            // let's add back in the o
            // cerr << "Derive mid " << mid << " from " << queryTriangleSumNoProc(fromIndex + 1, toIndex) << " - " << querySum(fromIndex + 1, toIndex) << " + " <<  (newValue * (toIndex + 1)) << endl;
            mid += newValue * (toIndex + 1);
            // cerr << "Deriving from " << normalTriangle << " - " << queryTriangleSumNoProc(fromIndex, toIndex) << " + " << mid << endl;
            long long ans = normalTriangle - (queryTriangleSumNoProc(fromIndex, toIndex) /* subtract old mid */) + mid;
            cout << ans << endl;
        }else if(fromIndex == toIndex){
            // value decreased position is the same
            long long ans = normalTriangle + ((newValue - oldVal) * (fromIndex + 1));
            cout << ans << endl;
        }else{
            // cerr << " un impl " << fromIndex << " " << toIndex << endl;
            // to index < from index
            // xxxxo shift to
            // oxxxx
            long long mid = queryTriangleSumNoProc(toIndex, fromIndex - 1) + querySum(toIndex, fromIndex - 1);
            // let's add back in the o
            mid += newValue * (toIndex + 1);
            long long ans = normalTriangle - (queryTriangleSumNoProc(toIndex, fromIndex) /* subtract old mid */) + mid;
            cout << ans << endl;
        }
    }
}

void selftest(){
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 4;
    arr[3] = 5;
    arr[4] = 7;
    arr[5] = 9;
    N = 6;
    buildPs();
    // cout << querySum(2,4) << " = " << 16 << endl;
    assert(querySum(2,4) == 16);
    assert(queryTriangleSum(1,4) == (1*1 + 2*4 + 3*5 + 4*7));
}

int main(int argc, char const *argv[])
{
    selftest();
    // cerr << "Self test pass" << endl;
    solve();
    return 0;
}
