#include <bits/stdc++.h>

using namespace std;

const int MAX = 100123;
int n, m, l, cnt;
int a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> l;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i-1] <= l && a[i] > l)
            ++cnt;
    }
    int t, p, d;
    while (m--) {
        cin >> t;
        if (t == 0) cout << cnt << '\n';
        else {
            cin >> p >> d;
            // if (a[p] > l) continue;
            a[p] += d;
            cerr << a[p] << ' ';
            if (a[p] > l) {
                if (a[p-1] <= l && a[p+1] <= l)
                    ++cnt;
                else if (a[p-1] > l && a[p+1] > l)
                    --cnt;
            }
        }
    }

    return 0;
}
