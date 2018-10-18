#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 30;
int n, h, h12, fish, f[N_MAX], d[N_MAX], t[N_MAX];

void dfs(int T, int I, int F, vector<int> &ans, vector<int> &cur)
{
    if (T < 0)
        return;
    if (F > fish) {
        ans = cur;
        fish = F;
    }
    if (!T || I == n) {
        return;
    }
    if (f[I] > 0) {
        f[I] -= d[I];
        cur[I]++;
        dfs(T-1, I, F+f[I]+d[I], ans, cur);
        cur[I]--;
        f[I] += d[I];
    }
    if (T >= t[I])
        dfs(T-t[I], I+1, F, ans, cur);
}

int main()
{
    bool first = true;
    while (cin >> n && n) {
        if (!first) cout << '\n';
        first = false;

        cin >> h;
        for (int i = 0; i < n; ++i)
            cin >> f[i];
        for (int i = 0; i < n; ++i)
            cin >> d[i];
        for (int i = 0; i < n-1; ++i)
            cin >> t[i];

        vector<int> ans(n), cur(n);
        fish = 0;
        dfs(h*12, 0, 0, ans, cur);
        int travel = 0;
        bool go = false;
        for (int i = n-1; i >= 0; --i) {
            if (ans[i]) go = true;
            if (i && go) travel += t[i-1];
            travel += ans[i];
        }
        ans[0] += h*12-travel;
        for (int i = 0; i < n; ++i) {
            if (i) cout << ", ";
            cout << ans[i]*5;
        }
        cout << "\nNumber of fish expected: " << fish << '\n';
    }

    return 0;
}
