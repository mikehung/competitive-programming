#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> cnts;

void calc(const vector<int> &a, int pos)
{
    if (a.size() <= 1 || pos < 0) return;

    vector<vector<int>> b(2);
    for (auto x: a) {
        int v = (x>>pos) & 1;
        cnts[pos][v] += b[v^1].size();
        b[v].push_back(x);
    }

    calc(b[0], pos-1);
    calc(b[1], pos-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it: a) cin >> it;

    cnts = vector<vector<ll>>(32, vector<ll>(2));
    calc(a, 31);
    ll an = 0, x = 0;
    for (int i = 0; i < 32; ++i) {
        if (cnts[i][0] > cnts[i][1]) {
            x |= (1<<i);
        }
        an += min(cnts[i][0], cnts[i][1]);
    }
    cout << an << ' ' << x << '\n';
    return 0;
}
