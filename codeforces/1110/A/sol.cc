#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int b, k;
    vector<int> a;
    cin >> b >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int r = 0, x = 1;
    for (int i = k-1; i >= 0; --i) {
        r += a[i] * x;
        r %= 2;
        x *= b;
        x %= 10;
    }
    cout << (r % 2 ? "odd" : "even") << endl;

    return 0;
}
