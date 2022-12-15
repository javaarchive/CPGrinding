#include <iostream>

using namespace std;

int subsolve(int W, int O, int B, int Cow, int Cbo, int Cbw) {
    // cout << "W: " << W << " O: " << O << " B: " << B << endl;
    // cout << "O < --- > W " << Cow << endl;
    // cout << "B < --- > O " << Cbo << endl;
    // cout << "B < --- > W " << Cbw << endl;
    int localBest = INT32_MAX;
    // all to white
    localBest = min(localBest, O * Cow + B * Cbw);
    // cout << " naive " << localBest << endl;
    localBest = min(localBest, B * Cbw + (Cbo + Cbw) * O);
    // cout << " intermid local brown " << localBest << endl;
    localBest = min(localBest, O * Cow + (Cbo + Cbw) * B);
    // cout << " intermid local orange " << localBest << endl;
    return localBest;
}

/**
 * Return the minimum cost to convert all of the paint into a single color.
 * 
 * W: non-negative number of buckets of white paint
 * O: non-negative number of buckets of orange paint
 * B: non-negative number of buckets of brown paint
 * Cow: positive cost to convert between a bucket of orange and white paint
 * Cbo: positive cost to convert between a bucket of brown and orange paint
 * Cbw: positive cost to convert between a bucket of brown and white paint
 */
int solve(int W, int O, int B, int Cow, int Cbo, int Cbw) {
    int minCost = INT32_MAX;
    // minCost = min(minCost, Cow * O + Cbw * B); // All to white
    // minCost = min(minCost, Cbo * O + Cbw * W); // All to brown
    // minCost = min(minCost, Cow * W + Cbo * B); // All to orange

    // minCost = min(minCost, Cow * O + (Cbo + Cow) * B); // orange to white, blue to orange to white
    // minCost = min(minCost, Cbo * O + (Cow + Cbo) * W); // orange to brown, white to orange to brown
    // minCost = min(minCost, Cbw * W + (Cow + Cbw) * B); // white to brown, orange to white to brown
    // minCost = min(minCost, Cow * W + (Cbw + Cow) * O); // white to orange, brown to white to orange
    // minCost = min(minCost, Cbo * B + (Cbw + Cbo) * W); // brown to orange, white to brown to orange
    // minCost = min(minCost, Cbw * B + (Cbo + Cbw) * O); // brown to white, orange to brown to white

    minCost = min(minCost, subsolve(W, O, B, Cow, Cbo, Cbw));
    minCost = min(minCost, subsolve(W, B, O, Cbw, Cbo, Cow));
    minCost = min(minCost, subsolve(O, W, B, Cow, Cbw, Cbo));
    minCost = min(minCost, subsolve(O, B, W, Cbo, Cbw, Cow));
    minCost = min(minCost, subsolve(B, W, O, Cbw, Cow, Cbo));
    minCost = min(minCost, subsolve(B, O, W, Cbo, Cow, Cbw));

    return minCost;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int W, O, B, Cow, Cbo, Cbw;
        cin >> W >> O >> B >> Cow >> Cbo >> Cbw;
        cout << solve(W, O, B, Cow, Cbo, Cbw) << endl;
    }
}
