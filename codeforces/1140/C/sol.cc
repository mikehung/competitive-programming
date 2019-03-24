#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 3e5+11;
int n, k, t, b;
pair<int, int> a[MAX];

bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first > p2.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> t >> b;
        a[i] = make_pair(b, t);
    }
    sort(a, a+n, cmp);

    multiset<int> s;
    long long L = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        L += a[i].second;
        s.insert(a[i].second);
        if (s.size() > k) {
            L -= *s.begin();
            s.erase(s.begin());
        }
        ans = max(ans, 1ll * a[i].first * L);
    }
    cout << ans << '\n';
    return 0;
}
