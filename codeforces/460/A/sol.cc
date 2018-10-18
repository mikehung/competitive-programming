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
    int n, m, cnt = 0;
    cin >> n >> m;
    while (n >= m) {
        cnt += m;
        n -= m-1;
    }
    cnt += n;
    cout << cnt << '\n';

    return 0;
}
