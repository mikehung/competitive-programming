#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 105;
int n, a[MAX], cnt[MAX], nice, other;
bool odd;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (int i = 0; i < MAX; ++i) {
        if (cnt[i] == 1)
            ++nice;
        else if (cnt[i] > 2)
            ++other;
    }
    if (nice & 1)
        odd = true;
    if (odd && !other) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    nice /= 2;
    string ans;
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] == 1 && nice) {
            ans += 'A';
            --nice;
        } else {
            if (cnt[a[i]] > 2 && odd) {
                ans += 'A';
                odd = false;
            } else {
                ans += 'B';
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
