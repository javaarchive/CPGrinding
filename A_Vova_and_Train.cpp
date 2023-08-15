    #include <bits/stdc++.h>
    using namespace std;

    // v: lantern multiplier
    int T, L, v, l, r;

    void solve(){
        cin >> L >> v >> l >> r;
        int ans = L / v;
        if(l % v != 0) l = (l - l % v) + v;
        if(r % v != 0) r = r - (r % v);
        ans -= (r - l) / v + 1;
        cout << ans << endl;
    }

    int main(int argc, char const *argv[])
    {
        cin >> T;
        while(T --) solve();
        return 0;
    }
