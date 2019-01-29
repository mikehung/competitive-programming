#include <bits/stdc++.h>

using namespace std;

int n, d = 0;
string s;
vector<char> colors = {'R', 'G', 'B'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            ++d;
            for (char color: colors) {
                if (color != s[i-1] && (i == n || color != s[i+1])) {
                    s[i] = color;
                    break;
                }
            }
        }
    }
    cout << d << '\n' << s << '\n';
    return 0;
}
