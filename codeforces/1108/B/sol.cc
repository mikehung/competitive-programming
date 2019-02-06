#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mx;
    multiset<int> s;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    mx = *prev(s.end());
    for (int i = 1; i <= mx; ++i) if (mx % i == 0) {
        s.erase(s.find(i));
    }
    cout << mx << ' ' << *prev(s.end()) << '\n';
    return 0;
}
