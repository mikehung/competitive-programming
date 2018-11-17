#include <bits/stdc++.h>

using namespace std;

const int MAX = 1234;
int n, a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    a[n] = 1001;
    int i = 0, j = 0, ans = 0;
    for (; j < n; ++j) {
        int cur = j - i - 1;
        if ((i == 0 && a[0] == 1) || (j == n-1 && ajn-1] == 1000)) ++cur;
        ans = max(ans, cur);
        if (a[j] + 1 != a[j+1]) {
            i = j + 1;
        }
    }
    cout << (ans >= 0 ? ans : -1) << '\n';
    return 0;
}
