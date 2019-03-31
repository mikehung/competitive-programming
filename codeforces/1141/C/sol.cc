#include <bits/stdc++.h>

using namespace std;

int n, mn;

bool check(vector<int> a)
{
    sort(a.begin(), a.end());
    for (int i = 0; i < n-1; ++i) {
        if (a[i] != a[i+1]-1) return false;
    }
    mn = a[0];
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    if (!check(a)) {
        cout << -1 << endl;
        return 0;
    }
    int df = 1 - mn;
    vector<int> an(n);
    for (int i = 0; i < n; ++i) {
        an[i] = a[i] + df;
        if (an[i] < 1 || an[i] > n) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << an[i] <<  ' ';
    }
    cout << endl;
    return 0;
}
