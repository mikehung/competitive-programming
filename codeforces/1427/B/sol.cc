#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<pair<int, int>> pars;
        for (int i = 0; i < n; ++i) if (s[i] == 'L') {
            int j = i;
            while (j < n && s[j] == 'L') ++j;
            if (i != 0 && j != n) {
                pars.push_back({i, j});
            }
            i = j-1;
        }
        sort(pars.begin(), pars.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.second-p1.first < p2.second-p2.first;        
        });
        for (auto &par: pars) {
            if (k >= par.second-par.first) {
                for (int i = par.first; i < par.second; ++i) {
                    s[i] = 'W';
                    --k;
                }
            }
        }
        for (int i = 1; i < n && k; ++i) if (s[i] == 'L' && s[i-1] == 'W') {
            s[i] = 'W';
            --k;
        }
        for (int i = n-2; i >= 0 && k; --i) if (s[i] == 'L' && s[i+1] == 'W') {
            s[i] = 'W';
            --k;
        }
        for (int i = 0; i < n && k; ++i) if (s[i] == 'L') {
            s[i] = 'W';
            --k;
        }
        int an = 0;
        for (int i = 0; i < n; ++i) if (s[i] == 'W') {
            if (i == 0 || s[i-1] == 'L') {
                an += 1;
            } else {
                an += 2;
            }
        }
        cout << an << '\n';
    }
    return 0;
}
