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
    int n, k, v;
    cin >> n >> k;
    vector<int> ans = {1};
    for (int d = 1; d < k; ++d) {
        if (d & 1)
            v = n-d;
        else
            v = -n+d;
        ans.push_back(ans.back()+v);
    }
    v = (k & 1) ? 1 : -1;
    for (int i = k; i < n; ++i) {
        ans.push_back(ans.back()+v);
    }
    for (auto &x : ans)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
