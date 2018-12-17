#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, p, t;
    vector<pair<int, int>> points;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> p >> t;
        points.push_back(make_pair(p, t));
    }
    sort(points.begin(), points.end(), cmp);
    --k;
    int i, j;
    for (i = k-1; i >= 0; --i) {
        if (points[i] != points[k]) break;
    }
    for (j = k+1; j < n; ++j) {
        if (points[j] != points[k]) break;
    }
    cout << j - i - 1 << '\n';
    return 0;
}
