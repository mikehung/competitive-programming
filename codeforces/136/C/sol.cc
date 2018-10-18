#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[n-1] == 1) {
        for (int i = 0; i < n-1; ++i)
            cout << 1 << ' ';
        cout << 2 << '\n';
    } else {
        cout << 1 << ' ';
        for (int i = 1; i < n; ++i)
            cout << a[i-1] << ' ';
        cout << '\n';
    }

    return 0;
}
