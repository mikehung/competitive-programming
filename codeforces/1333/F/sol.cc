#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0] = n+10, a[1] = 1;
    for (int i = 2; i <= n; ++i) if (a[i] == 0) {
        for (int j = i; j <= n; j+=i) if (a[j] == 0) {
            a[j] = j/i;
        }
    }
    sort(a.begin(), a.end());

    for (int i = 1; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
