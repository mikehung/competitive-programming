#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a, b, an;

void shift(int i)
{
    int tmp = a[i+2];
    a[i+2] = a[i+1];
    a[i+1] = a[i];
    a[i] = tmp;
}

void calc()
{
    for (int i = 0; i < n-2; ++i) if (a[i] != b[i]) {
        int j;
        for (j = i+1; j < n; ++j) {
            if (a[j] == b[i]) break;
        }
        // j -> i
        while (j != i) {
            if (i+1 != j) {
                shift(j-2);
                an.push_back(j-2);
                j -= 2;
            } else {
                shift(i);
                an.push_back(i);
                j++;
            }
        }
    }
}

bool check()
{
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear(), b.clear(), an.clear();
        a.resize(n);
        for (auto &it: a) cin >> it;
        b = a;
        sort(b.begin(), b.end());
        calc();
        if (!check()) {
            for (int i = n-4; i >= 0; --i) {
                if (a[i] == a[i+1]) {
                    for (auto j: {i, i, i+1, i+1}) {
                        shift(j);
                        an.push_back(j);
                    }
                    break;
                }
            }
            calc();
        }
        if (!(a[n-3] <= a[n-2] && a[n-2] <= a[n-1])) {
            shift(n-3);
            an.push_back(n-3);
        }
        if (check()) {
            cout << an.size() << '\n';
            for (auto x: an) cout << x+1 << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
