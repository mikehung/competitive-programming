#include <bits/stdc++.h>

using namespace std;

const int B_MAX = 35;
int n, k;
vector<int> ans;
long long b[B_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if (n < k) {
        cout << "NO\n";
        return 0;
    }
    long long x = 1;
    for (int i = 0; i < B_MAX; ++i, x *= 2) {
        b[i] = x - 1;
    }
    long long left = n - k;
    while (left) {
        if (!k) {
            cout << "NO\n";
            return 0;
        }
        int offset = upper_bound(b, b+B_MAX, left) - b - 1;
        left -= b[offset];
        ans.push_back(b[offset]+1);
        --k;
    }
    cout << "YES\n";
    for (auto x: ans) {
        cout << x << ' ';
    }
    while (k--) {
        cout << 1 << ' ';
    }
    cout << '\n';
    return 0;
}
