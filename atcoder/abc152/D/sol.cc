#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int cnt[10][10];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 1; i <= n; ++i) {
        int first = i, end = i % 10;
        while (first >= 10) first /= 10;
        cnt[first][end]++;
    }

    int an = 0;
    for (int i = 1; i <= n; ++i) {
        int first = i, end = i % 10;
        while (first >= 10) first /= 10;
        an += cnt[end][first];
    }
    cout << an << '\n';

    return 0;
}
