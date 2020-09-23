#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
vector<int> facs, cnts;
vector<vector<int>> lst;

void dfs(vector<int> &v, int idx)
{
    int sz = facs.size(), mp = -1, val = 1;
    for (int i = 0; i < sz; ++i) {
        if (v[i] > cnts[i]) {
            return;
        }

        if (v[i]) {
            if (mp == -1) mp = i;
            for (int j = 0; j < v[i]; ++j) {
                val *= facs[i];
            }
        }
    }

    if (val == n) mp = sz-1;
    if (mp != -1) {
        lst[mp].push_back(val);
    }

    for (int i = idx; i < sz; ++i) {
        v[i]++;
        dfs(v, i);
        v[i]--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int N = (int)1e5+11;
    vector<ll> primes;
    vector<bool> b(N, true);
    b[0] = b[1] = false;
    for (ll i = 2; i < N; ++i) {
        if (b[i]) {
            primes.push_back(i);
            for (ll j = i*i; j < N; j += i) {
                b[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        m = n;

        facs.clear();
        cnts.clear();
        lst.clear();

        for (ll i = 2; i*i <= n; ++i) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    ++cnt;
                    n /= i;
                }
                facs.push_back(i);
                cnts.push_back(cnt);
            }
        }
        if (n > 2) {
            facs.push_back(n);
            cnts.push_back(1);
        }
        n = m;

        lst.resize(facs.size());
        vector<int> v(facs.size());
        dfs(v, 0);

        for (int i = 0; i < lst.size(); ++i) {
            for (auto &x: lst[i]) {
                if (x % facs[(i+1)%facs.size()] == 0) {
                    swap(x, lst[i].back());
                }
            }

            for (auto x: lst[i]) {
                cout << x << ' ';
            }
        }

        cout << '\n';
        cout << int(lst.size() == 2 && cnts[0] == 1 && cnts[1] == 1) << '\n';
    }
    return 0;
}
