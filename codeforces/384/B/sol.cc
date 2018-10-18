#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int n, m, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<int, int>> ans;
    cin >> n >> m >> k;
    while (n--) {
        vector<int> a;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if (k)
                x = -x;
            a.push_back(x);
        }
        for (auto &par: ans) {
            if (k) {
                if (a[par.first] < a[par.second])
                    swap(a[par.first], a[par.second]);
            } else {
                if (a[par.first] > a[par.second])
                    swap(a[par.first], a[par.second]);
            }
        }
        map<int, int> b;
        for (int i = 0; i < m; ++i)
            b[a[i]] = i;
        int i = 0;
        map<int, int>::iterator it = b.begin();
        for (; i < m; ++i, ++it) {
            if (a[i] != it->first) {
                int j = it->second;
                if (k)
                    ans.emplace_back(j, i);
                else
                    ans.emplace_back(i, j);
                swap(b[a[i]], b[a[j]]);
                swap(a[i], a[j]);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto &par: ans)
        cout << par.first+1 << ' ' << par.second+1 << '\n';

    return 0;
}
