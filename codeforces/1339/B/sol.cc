#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        sort(a.begin(), a.end());
        int i = (n-1)/2;
        int j = i+1;
        while (i >= 0 || j < n) {
            if (i >= 0) cout << a[i--] << ' ';
            if (j < n) cout << a[j++] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
