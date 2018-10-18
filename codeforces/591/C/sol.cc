#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 5*1e5+5;
int n, a[MAX], ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if (j == n-1 || a[j] == a[j+1]) {
            int l = j - i + 1;
            ans = max(ans, (l+1)/2-1);
            for (int k = i+1; k < j; ++k) {
                if (k < i+(l/2)) {
                    a[k] = a[i];
                } else {
                    a[k] = a[j];
                }
            }
            i = j+1;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i != n-1) {
            cout << ' ';
        } else {
            cout << '\n';
        }
    }

    return 0;
}
