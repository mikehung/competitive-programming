#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5 + 11;
int n, m, k, a[MAX], b[MAX];
pair<int, int> seg[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (i) {
            seg[i-1] = make_pair(b[i] - b[i-1] - 1, i);
        }
    }
    sort(seg, seg+n-1);
    int res = n;
    for (int i = 0; i < n - k; ++i) {
        res += seg[i].first;
    }
    cout << res << endl;
    return 0;
}
