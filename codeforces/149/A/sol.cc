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
    int k, x, ans = 0;
    vector<int> a;
    cin >> k;
    while (cin >> x)
        a.push_back(x);
    sort(a.rbegin(), a.rend());
    int i = 0;
    while (k > 0 && i < 12) {
        ++ans;
        k -= a[i++];
    }
    if (k > 0)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}
