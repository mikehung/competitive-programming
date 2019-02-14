#include <bits/stdc++.h>

using namespace std;

const int MMAX = 41;
int n, m, t, dp1[1 << (MMAX/2)], dp2[1 << (MMAX/2)];
string name;
map<string, int> ids;
bool g[MMAX][MMAX];

void setmax(int &x, int y)
{
    if (y > x) x = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    set<int> friends;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t == 2) {
            cin >> name;
            if (!ids.count(name)) {
                int sz = ids.size();
                ids[name] = sz;
            }
            friends.insert(ids[name]);
        }
        if (t == 1 || i == n-1) {
            for (auto x: friends) for (auto y: friends) if (x != y) {
                g[x][y] = g[y][x] = 1;
            }
            friends.clear();
        }
    }
    int sz1 = ids.size() / 2, sz2 = ids.size() - sz1, ans = 0, ok;
    for (int i = 0; i < (1 << sz1); ++i) {
        for (int j = 0; j < sz1; ++j) if ((~i >> j) & 1) {
            ok = 1;
            for (int k = 0; k < sz1; ++k) if ((i >> k) & 1) {
                if (g[j][k]) {
                    ok = 0;
                    break;
                }
            }
            setmax(dp1[i | (1 << j)], dp1[i] + ok);
        }
        setmax(ans, dp1[i]);
    }
    for (int i = 0; i < (1 << sz2); ++i) {
        for (int j = 0; j < sz2; ++j) if ((~i >> j) & 1) {
            ok = 1;
            for (int k = 0; k < sz2; ++k) if ((i >> k) & 1) {
                if (g[j+sz1][k+sz1]) {
                    ok = 0;
                    break;
                }
            }
            setmax(dp2[i | (1 << j)], dp2[i] + ok);
        }
        setmax(ans, dp2[i]);
    }
    for (int i = 0; i < (1 << sz1); ++i) if (dp1[i]) {
        int mask = (1 << sz2) - 1;
        for (int j = 0; j < sz1; ++j) if ((i >> j) & 1) {
            for (int k = 0; k < sz2; ++k) if (g[j][k+sz1]) {
                mask &= ~(1 << k);
            }
        }
        setmax(ans, dp1[i] + dp2[mask]);
    }
    cout << ans << endl;
    return 0;
}
