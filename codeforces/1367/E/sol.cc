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
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> cnts(26);
        for (char ch: s) {
            cnts[ch-'a']++;
        }
        sort(cnts.rbegin(), cnts.rend());

        for (int sz = n; sz; --sz) {
            bool ok = false;

            int gsz = sz / gcd(sz, k);
            int gcnt = sz / gsz;
            for (int cnt: cnts) {
                gcnt -= cnt/gsz;
            }
            if (gcnt <= 0) {
                ok = true;
            }

            if (ok) {
                cout << sz << '\n';
                break;
            }
        }
    }
    return 0;
}
