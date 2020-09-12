#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, s, nn;
        cin >> n >> s;
        int sum = 0;
        vector<int> v;
        nn = n;
        while (nn) {
            v.push_back(nn%10);
            sum += v.back();
            nn /= 10;
        }

        int i = 0;
        while (sum > s) {
            if (v[i] == 0) {
                ++i;
                continue;
            }
            if (i+1 >= v.size()) v.push_back(0);
            sum -= v[i]-1;
            v[i+1]++;
            v[i] = 0;
            ++i;
        }
        ll m = 0;
        for (ll i = 0, b = 1; i < v.size(); ++i, b *= 10) {
            m += v[i] * b;
        }
        cout << m - n << '\n';
    }
    return 0;
}
