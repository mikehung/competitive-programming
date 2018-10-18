#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 3e5 + 5;
int n, m, l, r, x, nxt[MAX], ans[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        nxt[i] = i+1;
    }
    while (m--) {
        cin >> l >> r >> x;
        int i = l;
        while (i <= r) {
            int j = nxt[i];
            if (i != x && ans[i] == 0) {
                ans[i] = x;
            }
            if (i < x)
                nxt[i] = max(nxt[i], x);
            else
                nxt[i] = max(nxt[i], r+1);
            i = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
