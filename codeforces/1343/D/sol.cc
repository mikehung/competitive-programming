#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n/2), b(n/2);
        vector<int> cnt(2*k+2), pre(2*k+1);
        for (int i = 0; i < n/2; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n/2; ++i) {
            cin >> b[i];
        }
        reverse(b.begin(), b.end());
        for (int i = 0; i < n/2; ++i) {
            cnt[a[i]+b[i]]++;
            pre[min(a[i], b[i])+1]++;
            pre[max(a[i]+k, b[i]+k)+1]--;
        }
        for (int i = 1; i < 2*k+1; ++i) {
            pre[i] += pre[i-1];
        }

        int an = n;
        for (int i = 2; i <= 2*k; ++i) {
            int cur = 2*(n/2-pre[i]) + pre[i] - cnt[i];
            an = min(cur, an);
        }
        cout << an << '\n';
    }
    return 0;
}
