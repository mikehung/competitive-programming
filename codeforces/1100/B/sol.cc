#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, d;
    cin >> n >> m;
    int missing = n;
    vector<int> cnt(n);
    for (int i = 0; i < m; ++i) {
        cin >> d;
        --d;
        cnt[d]++;
        if (cnt[d] == 1) {
            missing -= 1;
        }
        if (missing == 0) {
            cout << 1;
            for (int j = 0; j < n; ++j) {
                --cnt[j];
                if (cnt[j] == 0) {
                    ++missing;
                }
            }
        } else {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
