#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long N;
    cin >> N;
    while(N != 1) {
        cout << N << " ";
        N = (N % 2 == 0) ? (N / 2) : (N * 3 + 1);
    }
    cout << 1 << " ";
    return 0;
}