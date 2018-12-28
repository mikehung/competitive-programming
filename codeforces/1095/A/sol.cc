#include <bits/stdc++.h>

using namespace std;
int n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int d = 0;
    for (int i = 0; i < n; i += d) {
        cout << s[i];
        ++d;
    }
    cout << '\n';
    return 0;
}
