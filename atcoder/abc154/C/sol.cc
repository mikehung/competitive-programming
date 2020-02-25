#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }
    if (s.size() == n) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
