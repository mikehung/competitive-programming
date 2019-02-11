#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, k, a[MAX];
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> s;
    long long ans = 0;
    int i = 0, j = 0;
    while (j < n) {
        vector<int> v;
        i = j;
        while (j+1 < n && s[j+1] == s[j]) {
            v.push_back(a[j++]);
        }
        v.push_back(a[j++]);
        sort(v.rbegin(), v.rend());
        for (int c = 0; c < v.size() && c < k; ++c) {
            ans += v[c];
        }
    }
    cout << ans << endl;
    return 0;
}
