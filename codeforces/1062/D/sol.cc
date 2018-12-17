#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> f;
    long long ans = 0;
    for (int i = 2; i <= n; ++i) if (n % i == 0) {
        f.push_back(i);
    }
    int sz = f.size();
    for (int i = 0; i < sz; ++i) for (int j = i+1; j < sz; ++j) {
        if (f[j] % f[i] == 0)
            ans += f[j] / f[i];
    }
    cout << 4LL * ans << '\n';
    return 0;
}
