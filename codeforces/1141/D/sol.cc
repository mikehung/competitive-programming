#include <bits/stdc++.h>

using namespace std;

int n;
char Q = '?';
string ls, rs;
map<char, vector<int>> lm, rm;
vector<pair<int, int>> an;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> ls >> rs;
    for (int i = 0; i < n; ++i) {
        lm[ls[i]].push_back(i+1);
        rm[rs[i]].push_back(i+1);
    }
    for (auto &[k, v1]: lm) if (k != Q && rm.count(k)) {
        auto &v2 = rm[k];
        while (v1.size() && v2.size()) {
            an.push_back({v1.back(), v2.back()});
            v1.pop_back();
            v2.pop_back();
        }
    }
    for (auto &[k, v]: lm) if (k != Q) {
        while (rm[Q].size() && v.size()) {
            an.push_back({v.back(), rm[Q].back()});
            rm[Q].pop_back();
            v.pop_back();
        }
    }
    for (auto &[k, v]: rm) if (k != Q) {
        while (lm[Q].size() && v.size()) {
            an.push_back({lm[Q].back(), v.back()});
            lm[Q].pop_back();
            v.pop_back();
        }
    }
    while (lm[Q].size() && rm[Q].size()) {
        an.push_back({lm[Q].back(), rm[Q].back()});
        lm[Q].pop_back();
        rm[Q].pop_back();
    }
    cout << (int) an.size() << endl;
    for (auto &[i, j]: an) {
        cout << i << ' ' << j << endl;
    }
    return 0;
}
