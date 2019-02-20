#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5 + 11;
int n, c[MAX], t[MAX];
multiset<int> s1, s2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (i) s1.insert(c[i]-c[i-1]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        if (i) s2.insert(t[i]-t[i-1]);
    }
    if (c[0] == t[0] && c[n-1] == t[n-1] && s1 == s2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
