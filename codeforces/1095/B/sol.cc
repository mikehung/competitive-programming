#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    cout << min(a[n-2] - a[0], a[n-1] - a[1]) << '\n';

    return 0;
}
