#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n, m, ans = 0;
    vector<int> a;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n && m && a[i] < 0; ++i, --m) {
        ans += -a[i];
    }
    cout << ans << '\n';

    return 0;
}
