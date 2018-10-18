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
    int n, m;
    deque<pair<int, int>> v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        v.emplace_back(x, i);
    }
    while (v.size() > 1) {
        auto p = v.front();
        v.pop_front();
        if (p.first > m)
            v.emplace_back(p.first-m, p.second);
    }
    cout << v[0].second << '\n';

    return 0;
}
