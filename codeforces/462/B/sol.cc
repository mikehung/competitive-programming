#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

string s;
int n, k;
long long ans;
const int MAX = 30;
vector<int> cnt(MAX);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    for (auto &ch: s) {
        ++cnt[ch-'A'];
    }
    sort(cnt.rbegin(), cnt.rend());
    for (int i = 0; i < 26 && k; ++i) {
        int v = min(k, cnt[i]);
        ans += 1LL*v*v;
        k -= v;
    }
    cout << ans << '\n';

    return 0;
}
