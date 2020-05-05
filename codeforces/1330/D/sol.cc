#include <bits/stdc++.h>

using namespace std;

int highest_bit(int x)
{
    int an = 0;
    while (x > 1) {
        ++an;
        x >>= 1;
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int d, m;
        cin >> d >> m;
        long long an = 1;
        for (int i = 0; i <= highest_bit(d); ++i) {
            int val = min((1<<(i+1))-1, d) - (1<<i) + 2;
            an = an*val % m;
        }
        cout << (an-1+m)%m << '\n';
    }
    return 0;
}
