#include <bits/stdc++.h>

using namespace std;

const int MAX = 22;
int n, ans[MAX][MAX];
map<int, int> cnt;
vector<int> v1, v2, v4;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n*n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
        if (cnt[x] == 4) {
            cnt[x] -= 4;
            if (cnt[x] == 0) {
                cnt.erase(x);
            }
            v4.push_back(x);
        }
    }
    for (auto &kv: cnt) {
        if (kv.second > 1) {
            kv.second -= 2;
            v2.push_back(kv.first);
        }
    }
    for (auto &kv: cnt) {
        if (kv.second == 1) {
            v1.push_back(kv.first);
        }
    }
    bool odd = n & 1, ok = true;
    int m = (n + 1) / 2, cc;
    for (int r = 0; r < m && ok; ++r) for (int c = 0; c < m && ok; ++c) {
        if (!odd) {
            cc = 4;
        } else {
            if (r == m-1 && c == m-1) {
                cc = 1;
            } else if (r == m-1 || c == m-1) {
                cc = 2;
            } else {
                cc = 4;
            }
        }
        if (cc == 1) {
            if (v1.empty()) {
                ok = false;
            } else {
                ans[r][c] = v1.back();
                v1.pop_back();
            }
        } else if (cc == 2) {
            if (v2.size()) {
                ans[r][c] = ans[n-1-r][c] = ans[r][n-1-c] = ans[n-1-r][n-1-c] = v2.back();
                v2.pop_back();
            } else {
                if (v4.empty()) {
                    ok = false;
                } else {
                    ans[r][c] = ans[n-1-r][c] = ans[r][n-1-c] = ans[n-1-r][n-1-c] = v4.back();
                    v4.pop_back();
                    v2.push_back(ans[r][c]);
                }
            }
        } else {
            if (v4.empty()) {
                ok = false;
            } else {
                ans[r][c] = ans[n-1-r][c] = ans[r][n-1-c] = ans[n-1-r][n-1-c] = v4.back();
                v4.pop_back();
            }
        }
    }
    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                cout << ans[r][c] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
