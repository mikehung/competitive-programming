#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

vector<long long> vec;

void dfs(int pos, int nonzero, long long cur)
{
    if (pos == 18) {
        vec.push_back(cur);
        return;
    }
    dfs(pos+1, nonzero, cur*10LL);
    if (nonzero < 3) {
        for (long long i = 1; i < 10; ++i) {
            dfs(pos+1, nonzero+1, cur*10LL+i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    long long lo, hi;
    cin >> T;
    dfs(0, 0, 0LL);
    vec.push_back(1e18);
    sort(vec.begin(), vec.end());
    while (T--) {
        cin >> lo >> hi;
        auto hit = upper_bound(vec.begin(), vec.end(), hi);
        auto lit = lower_bound(vec.begin(), vec.end(), lo);
        cout << hit-lit << '\n';
    }
    return 0;
}
