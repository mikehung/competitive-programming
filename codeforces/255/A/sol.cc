#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int n, x;
int cnt[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cnt[i%3] += x;
    }
    int mx = max(cnt[0], max(cnt[1], cnt[2]));
    if (cnt[0] == mx)
        puts("chest");
    if (cnt[1] == mx)
        puts("biceps");
    if (cnt[2] == mx)
        puts("back");

    return 0;
}
