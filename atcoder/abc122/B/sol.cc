#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, S("ATCG");
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (S.find(s[i]) != string::npos) {
            if (i == 0 || S.find(s[i-1]) == string::npos) {
                int j = i;
                while (S.find(s[j]) != string::npos) ++j;
                ans = max(ans, j-i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
