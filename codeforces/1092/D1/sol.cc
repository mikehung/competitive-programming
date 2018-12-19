#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5 + 112;
int n, a[MAX], b[MAX], mx;

bool check(int *a)
{
    vector<int> idx;
    for (int i = 0; i < n; ++i) if (a[i]) {
        if (!idx.empty() && (i - idx.back() & 1)) idx.pop_back();
        else idx.push_back(i);
    }
    return idx.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    for (int i = 0; i < n; ++i) {
        b[i] = (mx - a[i]) & 1;
    }
    // for (int i = 0; i < n; ++i) cerr << b[i] << ' '; cerr << '\n';
    if (check(b)) {
        cout << "YES\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        b[i] = 1 - b[i];
    }
    // for (int i = 0; i < n; ++i) cerr << b[i] << ' '; cerr << '\n';
    if (check(b)) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}
