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
    int n, cnt = 0, odd, even;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x & 1) {
            odd = i;
            ++cnt;
        } else {
            even = i;
        }
    }
    if (cnt == 1)
        cout << odd << '\n';
    else
        cout << even << '\n';

    return 0;
}
