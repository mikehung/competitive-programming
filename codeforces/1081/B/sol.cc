#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5 + 112;
int n, a[MAX];
map<int, vector<int>> same;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        same[n - a[i]].push_back(i);
    }
    bool ok = true;
    vector<int> ans(n);
    int id = 1;
    for (auto &kv: same) {
        while (kv.second.size() >= kv.first) {
            for (int i = 0; i < kv.first; ++i) {
                int pos = kv.second.back();
                kv.second.pop_back();
                ans[pos] = id;
            }
            ++id;
        }
        if (!kv.second.empty()) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "Impossible\n";
        return 0;
    }
    cout << "Possible\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
