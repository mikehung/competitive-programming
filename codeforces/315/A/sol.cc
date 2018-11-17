#include <bits/stdc++.h>

using namespace std;

const int MAX = 112;
int n, ans, a[MAX], b[MAX], stat[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (b[i] == a[j])
                stat[j] = true;
        }
    }
    for (int i = 0; i < n; ++i) if (!stat[i])
        ++ans;
    cout << ans << '\n';
    return 0;
}
