#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        string s;
        cin >> n >> q >> s;
        vector<int> one(n+1), zero(n+1);
        one[0] = zero[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                one[i+1] = 1;
            } else {
                zero[i+1] = 1;
            }
            one[i+1] += one[i];
            zero[i+1] += zero[i];
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            bool ok = false;
            if (s[l] == '1') {
                if (one[l] > 0) ok = true;
            } else {
                if (zero[l] > 0) ok = true;
            }
            if (s[r] == '1') {
                if (one[n]-one[r+1] > 0) ok = true;
            } else {
                if (zero[n]-zero[r+1] > 0) ok = true;
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
