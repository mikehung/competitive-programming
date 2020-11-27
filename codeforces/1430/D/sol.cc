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
        int n;
        string s;
        cin >> n >> s;

        vector<int> cnt;
        int i = 0, j = 0, an = 0;
        while (i < n) {
            j = i;
            while (j < n && s[j] == s[i]) ++j;
            cnt.push_back(j-i);
            i = j;
        }

        i = 0, j = 0, an = 0;
        while (i < cnt.size()) {
            ++an;
            while (j < cnt.size() && cnt[j] == 1) ++j;
            if (j < cnt.size() && cnt[j] > 1) {
                --cnt[j];
            } else {
                ++i;
            }
            ++i;
            j = max(j, i);
        }
        cout << an << '\n';
    }
    return 0;
}
