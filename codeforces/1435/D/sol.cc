#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void bye()
{
    cout << "NO\n";
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    vector<pair<char, vector<int>>> ops;
    for (int i = 0; i < 2*n; ++i) {
        char ch;
        cin >> ch;
        int y = 0;
        if (ch == '+') {
            ++cnt;
        } else {
            --cnt;
            if (cnt < 0) {
                bye();
            }
            cin >> y;
        }
        if (ops.empty() || ops.back().first != ch) {
            ops.push_back({ch, {}});
        }
        ops.back().second.push_back(y);
    }
    reverse(ops.begin(), ops.end());

    vector<int> an;
    priority_queue<int, vector<int>, greater<int>> left;
    for (auto &op: ops) {
        vector<int> &v = op.second;
        if (op.first == '+') {
            for (int i = 0; i < v.size(); ++i) {
                an.push_back(left.top());
                left.pop();
            }
        } else {
            // check ordering of -
            for (int i = 1; i < v.size(); ++i) {
                if (v[i] < v[i-1]) bye();
            }

            if (left.size() && left.top() < v.back()) bye();
            for (auto x: v) left.push(x);
        }
    }

    reverse(an.begin(), an.end());

    cout << "YES\n";
    for (auto x: an) cout << x << ' ';
    cout << '\n';

    return 0;
}
