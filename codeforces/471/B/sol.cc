#include <bits/stdc++.h>

using namespace std;

int n, h;
vector<pair<int, int>> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h;
        a.emplace_back(make_pair(h, i));
    }
    sort(a.begin(), a.end());
    vector<int> ids;
    for (int i = 0; i < n-1; ++i) {
        if (a[i].first == a[i+1].first)
            ids.emplace_back(i);
    }
    if ((int) ids.size() < 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i].second << ' ';
        }
        cout << '\n';
        swap(a[ids[0]], a[ids[0]+1]);
        for (int i = 0; i < n; ++i) {
            cout << a[i].second << ' ';
        }
        cout << '\n';
        swap(a[ids[1]], a[ids[1]+1]);
        for (int i = 0; i < n; ++i) {
            cout << a[i].second << ' ';
        }
        cout << '\n';
    }

    return 0;
}
