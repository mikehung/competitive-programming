#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = INT_MAX;
    for (int i = 0; i+2 < s.size(); ++i) {
        int v = (s[i]-'0')*100 + (s[i+1]-'0')*10 + (s[i+2]-'0');
        ans = min(ans, abs(v - 753));
    }
    cout << ans << endl;
    return 0;
}
