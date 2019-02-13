#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5 + 11;
int n, m, k, b[MAX];
vector<int> ans;
vector<pair<int, int>> a;
long long sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(make_pair(x, i));
    }
    sort(a.rbegin(), a.rbegin()+n);
    for (int i = 0; i < m*k; ++i) {
        sum += a[i].first;
        b[a[i].second] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            ++cnt;
            if (cnt == m) {
                cnt = 0;
                ans.push_back(i);
            }
        }
    }
    cout << sum << endl;
    for (int i = 0; i < k-1; ++i) {
        cout << ans[i]+1 << ' ';
    }
    cout << endl;
    return 0;
}
