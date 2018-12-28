#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5 + 12;
int n;
pair<int, int> a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> ans = {1};
    if (a[a[1].first].first == a[1].second || a[a[1].first].second == a[1].second) {
        ans.push_back(a[1].first);
        ans.push_back(a[1].second);
    } else {
        ans.push_back(a[1].second);
        ans.push_back(a[1].first);
    }
    for (int i = 1; ans.size() < n; ++i) {
        if (a[ans[i]].first != ans[i+1]) {
            ans.push_back(a[ans[i]].first);
        } else {
            ans.push_back(a[ans[i]].second);
        }
    }
    for (auto &x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
