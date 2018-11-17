#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mx = 0;
    map<int, int> cnt;
    cin >> n;
    while (n--) {
        int h, m;
        cin >> h >> m;
        cnt[h * 60 + m]++;
        mx = max(mx, cnt[h * 60 + m]);
    }
    cout << mx << '\n';
    return 0;
}
