#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+123;
int n, mn = MAX;
string s, ans, color = "RGB";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    sort(color.begin(), color.end());
    do {
        int diff = 0;
        string t;
        for (int p = 0; p < n; ++p) {
            t += color[p%3];
            if (color[p%3] != s[p]) ++diff;
        }
        if (diff < mn) {
            mn = diff;
            ans = t;
        }
    } while (next_permutation(color.begin(), color.end()));
    cout << mn << '\n' << ans << '\n';

    return 0;
}
