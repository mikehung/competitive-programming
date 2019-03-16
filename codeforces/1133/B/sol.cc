#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x % k]++;
    }
    int res = 2 * (cnt[0] / 2);
    for (int i = 1; i <= k/2; ++i) {
        int j = k - i;
        if (i != j) res += 2*min(cnt[i], cnt[j]);
        else res += 2 * (cnt[i] / 2);
    }
    cout << res << endl;

    return 0;
}
