#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MOD = 1e9+7;
    vector<long long> an(2e6+11);
    for (int i = 3; i < an.size(); ++i) {
        an[i] = (an[i-1] + 2*an[i-2] + int(i%3 == 0)) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << (4*an[x])%MOD << '\n';
    }
    return 0;
}
