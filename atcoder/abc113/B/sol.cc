#include <bits/stdc++.h>

using namespace std;

int n;
double t, a, diff = 1e9, an;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t >> a;
    for (int i = 0; i < n; ++i) {
        double h;
        cin >> h;
        double v = t - h * 0.006;
        if (abs(v-a) < diff) {
            diff = abs(v-a);
            an = i+1;
        }
    }
    cout << an << endl;
    return 0;
}
