#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 1e5;
int ans = INT_MAX, n, l[MAX], r[MAX];

int solve(int L, int R)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (l[i] != L) ++cnt;
        if (r[i] != R) ++cnt;
    }
    return cnt;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];
    ans = min(ans, solve(0, 0));
    ans = min(ans, solve(0, 1));
    ans = min(ans, solve(1, 0));
    ans = min(ans, solve(1, 1));
    cout << ans << '\n';

    return 0;
}
