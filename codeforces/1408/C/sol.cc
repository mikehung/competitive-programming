#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, l;
vector<double> b, c;

double calc(const vector<double> &a, double x)
{
    int speed = 1;
    double pos = 0;
    for (auto d: a) {
        double y = min(x, d/speed);
        pos += y*speed;
        x -= y;
        speed++;
    }
    return pos;
}

bool check(double x)
{
    double go1 = calc(b, x), go2 = calc(c, x);
    return go1 >= l-go2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> l;
        vector<double> a = {0};
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        a.push_back(l);

        b.resize(n+1);
        c.resize(n+1);
        for (int i = 0; i <= n; ++i) {
            b[i] = a[i+1]-a[i];
            c[i] = a[n+1-i]-a[n-i];
        }
        double l = 0, r = 1e9, m;
        for (int round = 0; round < 100; ++round) {
            m = (l+r)/2;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << setprecision(15) << fixed << r << '\n';
    }
    return 0;
}
