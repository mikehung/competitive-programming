#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0, i = 0;
    for (int j = 0; j < n; ++j) {
        ans = max(ans, j-i+1);
        if (j != n-1 && a[j] > a[j+1])
            i = j + 1;
    }
    cout << ans << '\n';
    return 0;
}
