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
    int i0 = -1, i1 = -1;
    for (int i = n-1; i >= 0; --i) {
        if (i0 == -1 && a[i] == 0) i0 = i;
        if (i1 == -1 && a[i] == 1) i1 = i;
    }
    cout << min(i0, i1) + 1 << endl;
    return 0;
}
