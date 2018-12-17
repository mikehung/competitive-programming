#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, vector<int>> cards;
    int n, x;
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> x;
        cards[x].push_back(i);
    }
    bool ok = true;
    for (auto &kv : cards) {
        if (kv.second.size() & 1)
            ok = false;
    }
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }
    for (auto &kv : cards) {
        for (int i = 0; i < kv.second.size(); i += 2) {
            cout << kv.second[i] << ' ' << kv.second[i+1] << '\n';
        }
    }
    return 0;
}
