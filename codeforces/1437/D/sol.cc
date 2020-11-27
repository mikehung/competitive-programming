#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), depth(n+1);
        deque<int> de;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            de.push_back(a[i]);
            if (i != 0 && a[i] < a[i-1]) {
                de.pop_front();
            }
            depth[a[i]] = depth[de.front()] + 1;
        }
        cout << depth[de.back()]-1 << '\n';
    }
    return 0;
}
