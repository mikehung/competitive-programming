#include <bits/stdc++.h>

using namespace std;

const int MAX = 123;
int n, a[MAX], ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n-1; ++i) {
        if (a[i-1] && !a[i] && a[i+1]) {
            ++ans;
            a[i+1] = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
