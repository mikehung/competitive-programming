#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < (int) s.size()-1; ++i) {
        if (s[i] != s[i+1]) {
            cout << "YES\n" << s[i] << s[i+1] << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
