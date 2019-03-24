#include <bits/stdc++.h>

using namespace std;

const int MAX = 5011;
int n, q, ok, p1[MAX];
vector<int> section[MAX];
int p2[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; ++j) if (section[j].size() <= 2) {
            section[j].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) if (section[i].size()) {
        ++ok;
        if (section[i].size() == 1) {
            p1[section[i][0]]++;
        } else if (section[i].size() == 2) {
            p2[section[i][0]][section[i][1]]++;
        }
    }
    int lost = MAX;
    for (int i = 0; i < q; ++i) for (int j = i+1; j < q; ++j) {
        lost = min(lost, p1[i] + p1[j] + p2[i][j]);
    }
    cout << ok - lost << '\n';
    return 0;
}
