#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int k;
string s;
map<char, int> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> s;
    for (char &ch: s) {
        ++cnt[ch];
    }
    string t;
    for (auto &kv: cnt) {
        if (kv.second % k) {
            cout << -1 << '\n';
            return 0;
        }
        int n = kv.second / k;
        while (n--) {
            t += kv.first;
        }
    }
    string ans;
    while (k--)
        ans += t;
    cout << ans << '\n';

    return 0;
}
