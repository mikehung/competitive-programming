#include <bits/stdc++.h>

using namespace std;

int calc(const vector<int> &v, int p)
{
    int an = 0;
    for (auto &x: v) {
        an += (x-p) * (x-p);
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v) cin >> x;

    int an = INT_MAX;
    for (int p = 1; p <= 100; ++p) {
        an = min(an, calc(v, p));
    }
    cout << an << endl;
    return 0;
}
