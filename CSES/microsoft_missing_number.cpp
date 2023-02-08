// the filename is because someone got into microsoft just because they luckily memorized an answer to a similar interview question where a number is duplicated
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long N;
    cin >> N;
    // expected
    long long expected = (N * (N + 1)) / 2;
    long long sum = 0;
    for(int i = 0; i < N - 1; i ++){
        int x;
        cin >> x;
        sum += x;
    }
    cout << expected - sum << endl;
    return 0;
}
