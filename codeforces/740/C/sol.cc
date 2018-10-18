#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = (int) 1e5 + 5;
int n, m, idx[N_MAX], l[N_MAX], r[N_MAX], mex = N_MAX + 1;

bool cmp(int i, int j)
{
    return l[i] < l[j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        --l[i], --r[i];
        mex = min(mex, r[i]-l[i]+1);
        idx[i] = i;
    }
    sort(idx, idx+m, cmp);
    vector<int> ans(n, N_MAX);
    for (int j = 0; j < m; ++j) {
        if (j != 0 && l[idx[j]] == l[idx[j-1]]) continue;
        for (int i = l[idx[j]]; i < l[idx[j]]+mex; ++i) {
            if (ans[i] != N_MAX) continue;
            if (i == 0 || ans[i-1] == N_MAX)
                ans[i] = 0;
            else
                ans[i] = (ans[i-1] + 1) % mex;
        }
    }
    cout << mex << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
