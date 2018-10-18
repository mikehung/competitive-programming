#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e5+5;
int n, L, a, t[MAX], l[MAX], cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> L >> a;
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> l[i];
    int start = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (t[i] - start) / a;
        start = t[i] + l[i];
    }
    cnt += (L - start) / a;
    cout << cnt << '\n';

    return 0;
}
