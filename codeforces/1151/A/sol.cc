#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t("ACTG");
    cin >> n >> s;
    int an = 1e9;
    for (int i = 0; i+3 < n; ++i) {
        int cur = 0;
        for (int j = 0; j < 4; ++j) {
            int v = t[j] - s[i+j];
            if (v < 0) v += 26;
            cur += min(v, 26-v);
        }
        an = min(an, cur);
    }
    cout << an << endl;
    return 0;
}
