#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 3010;
int n, a[MAX], h = 5000;
string name[MAX];
map<int, vector<int>> cnt;
vector<pair<int, int>> ans(MAX);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name[i] >> a[i];
        cnt[a[i]].push_back(i);
    }
    int qn = 0;
    for (auto &kv : cnt) {
        int ai = kv.first, pn = kv.second.size();
        if (ai > qn) {
            cout << -1 << '\n';
            return 0;
        }
        for (int i = qn-1; i >= ai; --i) {
            ans[i+pn] = ans[i];
        }
        for (int i = 0; i < pn; ++i) {
            ans[ai+i] = make_pair(h, kv.second[i]);
        }
        qn += pn;
        h--;
    }
    for (int i = 0; i < n; ++i) {
        auto &kv = ans[i];
        cout << name[kv.second] << ' ' << kv.first << '\n';
    }

    return 0;
}
