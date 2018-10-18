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
    int n, a;
    map<int, int> cnt;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (i < (n+1)/2)
            ++cnt[a-i];
        else
            ++cnt[a-(n-i-1)];
    }
    int ans = INT_MAX;
    for (auto &kv : cnt) {
        if (kv.first > 0) {
            ans = min(ans, n-kv.second);
        }
    }
    cout << ans << '\n';

    return 0;
}
