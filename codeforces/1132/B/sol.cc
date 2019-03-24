#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    long long s = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &v: a) {
        cin >> v;
        s += v;
    }
    sort(a.begin(), a.end());
    cin >> m;
    while (m--) {
        int b;
        cin >> b;
        cout << s - a[n-b] << '\n';
    }

    return 0;
}
