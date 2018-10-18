#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 100;
int n, m, a[MAX], b[MAX];
map<int, int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[j] % a[i] == 0)
                ++ans[b[j] / a[i]];
        }
    }
    cout << ans.rbegin()->second << '\n';

    return 0;
}
