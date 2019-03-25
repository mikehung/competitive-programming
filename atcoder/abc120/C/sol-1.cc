#include <bits/stdc++.h>

using namespace std;


void solve(string S)
{
    int ans = 0;
    vector<char> v;
    for (auto &c: S) {
        v.push_back(c);
        if (v.size() >= 2) {
            int n = v.size();
            if (v[n-1] != v[n-2]) {
                v.pop_back();
                v.pop_back();
                ans += 2;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    solve(S);
    return 0;
}
