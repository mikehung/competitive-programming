#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    sort(a.begin(), a.end());
    deque<int> d;
    for (int i = 0; i < n; ++i) {
        if (i & 1) d.push_front(a[i]);
        else d.push_back(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << d[i] << ' ';
    }
    cout << endl;
    return 0;
}
