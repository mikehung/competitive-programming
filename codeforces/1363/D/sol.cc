#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int resp;

void ask(int l, int r, const vector<vector<int>> &indices)
{
    int sz = 0;
    for (int i = l; i <= r; ++i) sz += indices[i].size();
    cout << "? " << sz;
    for (int i = l; i <= r; ++i) {
        for (auto x: indices[i]) cout << ' ' << x;
    }
    cout << endl;
    cin >> resp;
}

void ask(const vector<int> &a)
{
    cout << "? " << a.size();
    for (auto x: a) cout << ' ' << x;
    cout << endl;
    cin >> resp;
}

void answer(const vector<int> &an)
{
    cout << "!";
    for (auto x: an) cout << ' ' << x;
    cout << endl;

    string xx;
    cin >> xx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n+1);
        vector<vector<int>> indices(k);
        for (int i = 0; i < k; ++i) {
            int c;
            cin >> c;
            for (int j = 0; j < c; ++j) {
                int x;
                cin >> x;
                assert(a[x] == 0);
                a[x] = 1;
                indices[i].push_back(x);
            }
        }

        vector<int> rest, an(k);
        for (int i = 1; i <= n; ++i) if (a[i] == 0) {
            rest.push_back(i);
        }

        int mx_rest = -1, mx_subset = -1;
        ask(0, k-1, indices);
        mx_subset = resp;

        int lo = 0, hi = k-1, mid;
        while (lo < hi) {
            mid = lo + (hi-lo)/2;
            ask(lo, mid, indices);
            if (resp == mx_subset) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        // now, lo is subset with mx_subset
        a.assign(n+1, 0);
        rest.clear();
        for (auto x: indices[lo]) a[x] = 1;
        for (int i = 1; i <= n; ++i) if (a[i] == 0) {
            rest.push_back(i);
        }
        ask(rest);
        mx_rest = resp;

        an[lo] = mx_rest;
        for (int i = 0; i < k; ++i) if (i != lo) an[i] = max(mx_rest, mx_subset);
        answer(an);
    }
    return 0;
}
