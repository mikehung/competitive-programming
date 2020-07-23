#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        vector<int> an;
        int flip = 0;
        char ch;
        for (int i = 0, j = n-1; i <= n/2; ++i) {
            for (int k: {i, n-i-1}) if (j >= 0) {
                ch = a[k];
                if (flip) ch = ch == '1' ? '0' : '1';
                if (ch == b[j]) {
                    an.push_back(0);
                    an.push_back(j);
                } else {
                    an.push_back(j);
                }
                --j;
                flip = 1-flip;
            }
        }
        cout << an.size() << ' ';
        for (auto x: an) cout << x+1 << ' '; cout << '\n';
    }
    return 0;
}
