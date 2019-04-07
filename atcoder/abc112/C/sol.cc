#include <bits/stdc++.h>

using namespace std;

long long N, anx, any, anv;
vector<long long> x, y, h, zx, zy;


bool check()
{
    for (int i = 0; i < (int) zx.size(); ++i) {
        if (anv > abs(zx[i] - anx) + abs(zy[i] - any)) return false;
    }
    return true;
}

void solve()
{
    for (int cx = 0; cx <= 100; ++cx) for (int cy = 0; cy <= 100; ++cy) {
        bool ok = true;
        long long v = abs(cx-x[0]) + abs(cy-y[0]) + h[0];
        if (v == 0) continue;
        for (int i = 1; i < (int) x.size() && ok; ++i) {
            long long w = abs(cx-x[i]) + abs(cy-y[i]) + h[i];
            if (v != w) ok = false;
        }
        if (ok) {
            anx = cx, any = cy, anv = v;
            if (check()) {
                cout << anx << ' ' << any << ' ' << anv << endl;
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int X, Y, H;
        cin >> X >> Y >> H;
        if (H) {
            x.push_back(X);
            y.push_back(Y);
            h.push_back(H);
        } else {
            zx.push_back(X);
            zy.push_back(Y);
        }
    }
    solve();
    return 0;
}
