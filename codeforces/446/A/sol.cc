#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e5+5;
int n, a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int i = 0, v = -1, ch = -1, type = 0, ans = 0;
    for (int j = 0; j < n; ++j) {
        ans = max(ans, j-i+1);
        dbg("%d %d %d %d\n", i, j, a[i], a[j]);
        if (j+1 < n && a[j] >= a[j+1]) {
            if (type == 1) {
                i = ch + 1;
            } else if (type == 2){
                i = ch;
            }
            a[ch] = v;
            type = 0;
        }
        if (j+1 < n && a[j] >= a[j+1]) {
            if (j == 0 || a[j+1] - 1 > a[j-1]) {
                v = a[j];
                a[j] = a[j+1] - 1;
                ch = j;
                type = 1;
            } else {
                v = a[j+1];
                a[j+1] = a[j] + 1;
                ch = j + 1;
                type = 2;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
