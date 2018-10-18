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
    int n, l, r;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        p[i] = make_pair(l, r);
    }
    sort(p.begin(), p.end());
    vector<int> tv(2, -1);
    for (int i = 0; i < n; ++i) {
        if (tv[0] < p[i].first) {
            tv[0] = p[i].second;
        } else if (tv[1] < p[i].first) {
            tv[1] = p[i].second;
        } else {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    return 0;
}
