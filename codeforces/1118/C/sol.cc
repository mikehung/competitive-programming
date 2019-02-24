#include <bits/stdc++.h>

using namespace std;

const int MAX = 22;
int n, ans[MAX][MAX];
map<int, int> cnt;
priority_queue<pair<int, int>> q;

void no()
{
    cout << "NO\n";
    exit(0);
}

void put(vector<pair<int, int>> v)
{
    pair<int, int> el = q.top();
    q.pop();
    if (v.size() > el.first) {
        no();
    }
    for (auto &[r, c]: v) {
        ans[r][c] = el.second;
    }
    el.first -= v.size();
    q.push(el);
}

int rev(int i)
{
    return n - i - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n*n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    for (auto &[k, v]: cnt) {
        q.push({v, k});
    }
    int m = n / 2;
    for (int r = 0; r < m; ++r) for (int c = 0; c < m; ++c) {
        put({{r, c}, {rev(r), c}, {r, rev(c)}, {rev(r), rev(c)}});
    }
    if (n & 1) {
        for (int i = 0; i < m; ++i) {
            put({{i, m}, {rev(i), m}});
            put({{m, i}, {m, rev(i)}});
        }
        put({{m, m}});
    }
    cout << "YES\n";
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << ans[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
