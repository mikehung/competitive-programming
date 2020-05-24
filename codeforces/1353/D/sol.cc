#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<pair<int, int>> q;
        q.push({n, 0});  // size, -start
        vector<int> a(n);
        int i = 1;
        while (q.size()) {
            auto par = q.top();
            q.pop();
            int size = par.first, r = -par.second;
            int l = r+size-1, mid = (l+r)/2;

            a[(l+r)/2] = i++;
            if (r <= mid-1) {
                q.push({mid-r, -r});
            }
            if (mid+1 <= l) {
                q.push({l-mid, -(mid+1)});
            }
        }
        for (auto &it: a) cout << it << ' ';
        cout << '\n';
    }
    return 0;
}
