#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    vector<int> diff;
    if (a.size() != b.size()) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < (int) a.size(); ++i) {
        if (a[i] != b[i]) {
            diff.push_back(i);
        }
    }
    if ((int) diff.size() == 2 && a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[0]])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
