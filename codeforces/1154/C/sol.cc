#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, c, an = 0;
    cin >> a >> b >> c;
    long long x = min(a/3, min(b/2, c/2));
    vector<int> v(3);
    v[0] = a - 3*x;
    v[1] = b - 2*x;
    v[2] = c - 2*x;
    vector<int> food = {0, 1, 2, 0, 2, 1, 0};
    for (int i = 0; i < 7; ++i) {
        vector<int> b(v);
        long long cn = 0;
        for (int j = i; ; j = (j+1) % 7) {
            if (b[food[j]] == 0) break;
            ++cn;
            b[food[j]]--;
        }
        an = max(an, cn);
    }
    cout << x*7 + an << endl;
    return 0;
}
