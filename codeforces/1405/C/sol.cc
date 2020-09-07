#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        bool ok = true;
        for (int i = 0; i < k; ++i) {
            bool zero = false, one = false;
            for (int j = i; j < n; j += k) {
                if (s[j] == '0') zero = true;
                else if (s[j] == '1') one = true;
            }

            if (zero && one) {
                ok = false;
                break;
            }
            if (zero) cnt0++;
            if (one) cnt1++;
        }
        if (cnt0 > k/2 || cnt1 > k/2) {
            ok = false;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
