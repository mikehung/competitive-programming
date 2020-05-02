#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> alpha(26);
        for (int i = 0; i < n; ++i) {
            alpha[s[i]-'a']++;
        }
        if (k == 1) {
            for (int i = 0; i < 26; ++i) {
                while (alpha[i]) {
                    cout << (char)('a'+i);
                    alpha[i]--;
                }
            }
            cout << '\n';
            continue;
        }

        int cnt = 0, first = -1;
        for (int i = 0; i < 26; ++i) if (alpha[i]) {
            if (first == -1) first = alpha[i];
            ++cnt;
        }
        if (k > first) {
            for (int i = 0; i < 26; ++i) {
                while (alpha[i]) {
                    k--;
                    alpha[i]--;
                    if (k == 0) {
                        cout << (char)('a'+i) << '\n';
                        break;
                    }
                }
            }
        } else {
            int ncnt = cnt-1 + (first > k);
            if (ncnt >= 2) {
                for (int i = 0; i < 26; ++i) if (alpha[i]) {
                    alpha[i] -= k-1;
                    break;
                }
                for (int i = 0; i < 26; ++i) {
                    while (alpha[i]) {
                        cout << (char)('a'+i);
                        alpha[i]--;
                    }
                }
                cout << '\n';
            } else {
                vector<string> an(k);
                for (int i = 0, j = 0; i < 26; ++i) {
                    while (alpha[i]) {
                        alpha[i]--;
                        an[j].push_back('a'+i);
                        j = (j+1) % k;
                    }
                }
                string ans = an[0];
                for (int i = 0; i < k; ++i) ans = max(ans, an[i]);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
