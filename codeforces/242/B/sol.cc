#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif


const int MAX = (int) 1e5+5;
int n, l[MAX], r[MAX], L, R;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
        if (i == 1)
            L = l[i], R = r[i];
        else
            L = min(L, l[i]), R = max(R, r[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (l[i] == L && r[i] == R) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
