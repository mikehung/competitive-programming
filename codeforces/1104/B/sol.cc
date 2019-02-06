#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n, cnt = 0;
    cin >> s;
    n = s.size();
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (v.size() && v.back() == s[i]) {
            v.pop_back();
            ++cnt;
        } else {
            v.push_back(s[i]);
        }
    }
    if (cnt & 1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
