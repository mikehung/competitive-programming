#include <bits/stdc++.h>

using namespace std;

int n, resp, c1, c2, r1, r2;
vector<int> odd;

void query(int x1, int y1, int x2, int y2)
{
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    cin >> resp;
}

void answer(int x1, int y1, int x2, int y2)
{
    cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}

int calc_row(int c)
{
    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        query(1, c, mid, c);
        if (resp & 1) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return lo;
}

int calc_col(int r)
{
    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        query(r, 1, r, mid);
        if (resp & 1) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        query(1, i, n, i);
        if (resp & 1) odd.push_back(i);
    }
    if (odd.size()) {
        if (odd.size() == 1) odd.push_back(n);
        c1 = odd[0], c2 = odd[1];
        r1 = calc_row(c1), r2 = calc_row(c2);
        answer(r1, c1, r2, c2);
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        query(i, 1, i, n);
        if (resp & 1) odd.push_back(i);
    }
    if (odd.size() == 1) odd.push_back(n);
    r1 = odd[0], r2 = odd[1];
    c1 = calc_col(r1), c2 = calc_col(r2);
    answer(r1, c1, r2, c2);
    return 0;
}
