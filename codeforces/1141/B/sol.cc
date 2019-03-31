#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    for (int i = 0; i < n; ++i) {
        a.push_back(a[i]);
    }
    int j = 0, an = 0;
    for (int i = 0; i < 2*n; ++i) {
        if (a[i] == 0) {
            j = i+1;
        }
        an = max(an, i-j+1);
    }
    cout << an << endl;
    return 0;
}
