#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        int an = 0;
        vector<vector<int>> a(26, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            int u = s[i]-'a', v = t[i]-'a';
            if (u > v) {
                an = -1;
                break;
            } else {
                a[u][v] = 1;
            }
        }
        if (an == 0) {
            for (int from = 0; from < 26; ++from) {
                int update = -1;
                for (int to = from+1; to < 26; ++to) {
                    if (a[from][to]) {
                        ++an;
                        update = to;
                        break;
                    }
                }
                if (update != -1) {
                    for (int to = from+1; to < 26; ++to) {
                        if (a[from][to]) {
                            a[update][to] = 1;
                        }
                    }
                }
            }
        }
        cout << an << '\n';
    }
    return 0;
}
