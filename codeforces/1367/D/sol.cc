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
        string s;
        cin >> s;
        vector<int> words(26);
        for (auto ch: s) words[ch-'a']++;

        int n;
        cin >> n;
        vector<int> b(n), an(n, -1);
        for (auto &it: b) cin >> it;

        int w = 25;
        while (true) {
            vector<int> cnt0;
            for (int i = 0; i < n; ++i) if (an[i] == -1 && b[i] == 0) {
                cnt0.push_back(i);
            }
            if (cnt0.empty()) break;

            for (; w >= 0; --w) {
                if (words[w] >= cnt0.size()) {
                    for (int i: cnt0) {
                        an[i] = w;
                        for (int j = 0; j < n; ++j) if (an[j] == -1) {
                            b[j] -= abs(i-j);
                        }
                    }
                    --w;
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << (char) (an[i]+'a');
        }
        cout << '\n';
    }
    return 0;
}
