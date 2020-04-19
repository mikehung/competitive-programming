#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                string s;
                cin >> s;
                int v = s[3*j+i]-'0';
                v++;
                if (v == 10) v = 1;
                s[3*j+i] = v+'0';
                cout << s << '\n';
            }
        }
    }
    return 0;
}
