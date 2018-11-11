#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n > m) {
        for (int i = 0; i < n-m; ++i)
            cout << "B";
        for (int i = 0; i < m; ++i)
            cout << "GB";
        cout << '\n';
    } else {
        for (int i = 0; i < m-n; ++i)
            cout << "G";
        for (int i = 0; i < n; ++i)
            cout << "BG";
        cout << '\n';
    }
    return 0;
}
