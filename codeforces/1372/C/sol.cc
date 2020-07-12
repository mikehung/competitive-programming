#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &it: a) cin >> it;
        if (is_sorted(a.begin(), a.end())) {
            cout << 0 << '\n';
        } else {
            b = a;
            sort(b.begin(), b.end());
            int blk = 0;
            for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
                if (i == 0 || a[i-1] == b[i-1]) {
                    blk++;
                    if (blk == 2) {
                        break;
                    }
                }
            }
            cout << blk << '\n';
        }
    }
    return 0;
}
