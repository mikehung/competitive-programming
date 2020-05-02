#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, b = 1;
        cin >> n;
        while (b*4 <= n) {
            b *= 4;
        }
        ll diff = n - b;
        ll div = diff / 3, mod = diff % 3;
        ll base = b + div;

        vector<int> bits[3];
        while (base) {
            bits[0].push_back(base % 2);
            base /= 2;
        }
        bits[0].push_back(0);
        reverse(bits[0].begin(), bits[0].end());

        int sz = bits[0].size();
        bits[1] = vector<int>(sz);
        bits[2] = vector<int>(sz);

        bits[1][0] = 1, bits[1][1] = 0;
        for (int i = 2; i < sz; i += 2) {
            if (bits[0][i] == 0) {
                if (bits[0][i+1] == 1) bits[1][i] = 1, bits[1][i+1] = 0;
                else bits[1][i] = 0, bits[1][i+1] = 0;
            } else {
                if (bits[0][i+1] == 1) bits[1][i] = 0, bits[1][i+1] = 1;
                else bits[1][i] = 1, bits[1][i+1] = 1;
            }
        }

        for (int i = 0; i < sz; ++i) {
            bits[2][i] = bits[0][i] ^ bits[1][i];
        }

        ll an = 0;
        for (int i = 0; i < sz; ++i) if (bits[mod][i]) {
            an += (1ll << (sz-i-1));
        }
        cout << an << '\n';
    }
    return 0;
}
