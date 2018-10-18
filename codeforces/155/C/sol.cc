#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int S_MAX = (int) 1e5+5, C_MAX = 30;
string s, t;
int n, c1, c2, k, ans;
int group[S_MAX], id[C_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> k;
    n = s.size();
    for (int i = 1; i <= k; ++i) {
        cin >> t;
        id[t[0]-'a'] = id[t[1]-'a'] = i;
    }
    for (int i = 0; i < n; ++i) {
        group[i] = id[s[i]-'a'];
    }
    int g, j = 0, cnt[2];
    for (int i = 0; i < n; ++i) {
        if (i == n-1 || group[j] != group[i+1]) {
            if (group[j]) {
                cnt[0] = cnt[1] = 0;
                for (int k = j; k <= i; ++k)
                    cnt[(int) s[j] == s[k]]++;
                ans += min(cnt[0], cnt[1]);
            }
            j = i+1;
            g = group[i+1];
        }
    }
    cout << ans << '\n';

    return 0;
}
