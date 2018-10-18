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
    string s;
    vector<int> ans;
    cin >> n >> s;
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if (s[j] == 'W') {
            i = j + 1;
            continue;
        }
        if (j == n-1 || s[j+1] == 'W') {
            ans.push_back(j-i+1);
            i = j + 1;
        }
    }
    cout << ans.size() << '\n';
    if (!ans.empty()) {
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
