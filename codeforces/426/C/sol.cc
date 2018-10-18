#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int NMAX = 205;
int n, K, k, a[NMAX], b[NMAX];
vector<pair<int, int>> s;

int main()
{
    cin >> n >> K;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.emplace_back(a[i], i);
    }
    sort(s.rbegin(), s.rend());
    int ans = INT_MIN, cur;
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i+len-1 < n; ++i) {
            for (int j = 0; j < len; ++j)
                b[j] = a[i+j];
            sort(b, b+len);
            k = 0;
            for (int j = 0; j < n && k < K; ++j) {
                if (i <= s[j].second && s[j].second < i+len)
                    continue;
                if (s[j].first > b[k])
                    b[k++] = s[j].first;
                else if (s[j].first < b[k])
                    break;
            }
            cur = 0;
            for (int j = 0; j < len; ++j)
                cur += b[j];
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';

    return 0;
}
