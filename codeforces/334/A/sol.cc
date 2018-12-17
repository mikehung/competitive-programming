#include <bits/stdc++.h>

using namespace std;

const int MAX = 112;
int n, bag[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int k = i;
        for (int j = 0; j < n; ++j) {
            cout << k + n*j << ' ';
            ++k;
            if (k > n) k = 1;
        }
        cout << '\n';
    }
    return 0;
}
