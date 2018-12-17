#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<int> cnt(8);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 5 || x == 7) {
            cout << -1 << '\n';
            return 0;
        }
        cnt[x]++;
    }
    int t1 = cnt[4], t2 = cnt[2] - cnt[4], t3 = cnt[6] - cnt[2] + cnt[4];
    if (t1 < 0 || t2 < 0 || t3 < 0 || cnt[1] != t1+t2+t3 || cnt[2] != t1+t2 || cnt[3] != t3 || cnt[4] != t1 || cnt[6] != t2+t3) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < cnt[4]; ++i)
        cout << "1 2 4" << '\n';
    for (int i = 0; i < cnt[2] - cnt[4]; ++i)
        cout << "1 2 6" << '\n';
    for (int i = 0; i < cnt[6] - cnt[2] + cnt[4]; ++i)
        cout << "1 3 6" << '\n';
    return 0;
}
