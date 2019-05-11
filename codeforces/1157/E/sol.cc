#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> s;
    for (auto &v: a) cin >> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < n; ++i) {
        int x = n - a[i];
        auto it = s.lower_bound(x);
        if (it == s.end()) it = s.begin();
        cout << (a[i] + *it) % n << ' ';
        s.erase(it);
    }
    cout << endl;

    return 0;
}
