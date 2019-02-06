#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+11, MMAX = 211;
int n, m, k, coin[MAX], until[MAX];
vector<pair<int, int>> add[MAX], del[MAX];
long long dp[MAX][MMAX];

long long calc(int t, int d)
{
    if (t > n) return 0;
    if (dp[t][d] != -1) return dp[t][d];
    if (!coin[t]) return calc(t+1, d);
    long long v = coin[t] + calc(until[t]+1, d);
    if (d) v = min(v, calc(t+1, d-1));
    return dp[t][d] = v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < MAX; ++i) for (int j = 0; j < MMAX; ++j) dp[i][j] = -1;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        add[s].push_back(make_pair(-w, -d));
        del[t].push_back(make_pair(-w, -d));
    }
    multiset<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) {
        for (auto &par: add[i]) s.insert(par);
        if (s.size()) {
            coin[i] = -s.begin()->first;
            until[i] = -s.begin()->second;
        }
        for (auto &par: del[i]) s.erase(s.find(par));
    }
    cout << calc(1, m) << endl;
    return 0;
}
