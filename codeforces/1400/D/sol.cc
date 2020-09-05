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
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }

        ll an = 0;
        for (int i = 0; i+3 < n; ++i) {
            ll sum = 0;
            vector<ll> cnt1(n), cnt2(n);
            cnt1[a[i+1]] = 1;
            for (int j = i+3; j < n; ++j) {
                cnt2[a[j]]++;
            }
            for (int x = 0; x < n; ++x) {
                sum += cnt1[x] * cnt2[x];
            }

            for (int k = i+2; k < n-1; ++k) {
                if (a[i] == a[k]) {
                    an += sum;
                }
                int xx = a[k], yy = a[k+1];
                sum -= cnt1[xx] * cnt2[xx];
                if (xx != yy) sum -= cnt1[yy] * cnt2[yy];
                cnt1[xx]++, cnt2[yy]--;
                sum += cnt1[xx] * cnt2[xx];
                if (xx != yy) sum += cnt1[yy] * cnt2[yy];
            }
        }

        cout << an << '\n';
    }
    return 0;
}
