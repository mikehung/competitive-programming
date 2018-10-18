#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

long long n, k;
map<long long, long long> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    auto it = cnt.begin();
    long long cur = it->second * n;
    while (k > cur) {
        k -= cur;
        cur = (++it)->second * n;
    }
    auto jit = cnt.begin();
    cur = it->second * jit->second;
    while (k > cur) {
        k -= cur;
        cur = it->second * (++jit)->second;
    }
    cout << it->first << ' ' << jit->first << '\n';

    return 0;
}
