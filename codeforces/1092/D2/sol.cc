#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5 + 112;
int n, a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (v.empty()) {
            v.push_back(a[i]);
        } else {
            if (v.back() == a[i]) v.pop_back();
            else if (v.back() > a[i]) v.push_back(a[i]);
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (v.empty()) {
        cout << "YES\n";
    } else {
        if (v.size() == 1 && v[0] == *max_element(a, a+n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
