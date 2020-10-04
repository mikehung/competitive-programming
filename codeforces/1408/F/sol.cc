#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int>> an;
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j+2*i <= n; j += 2*i) {
            for (int k = 0; k < i && j+k+i < n; ++k) {
                an.push_back({j+k, j+k+i});
            }
        }
    }

    int front = 0;
    int end = n-1;
    vector<int> v;
    for (int i = 0; (1<<(i+1)) <= n; ++i) {
        if ((n >> i) & 1) {
            vector<int> v1;
            for (int j = 0; j < (1<<i); ++j) {
                v1.push_back(end--);
            }
            while (v.size() < v1.size()) {
                if (v.empty()) {
                    v.push_back(front++);
                } else {
                    int sz = v.size();
                    for (int j = 0; j < sz; ++j) {
                        an.push_back({v[j], front});
                        v.push_back(front++);
                    }
                }
            }

            for (int j = 0; j < v.size(); ++j) {
                an.push_back({v[j], v1[j]});
            }
            for (int j = 0; j < v1.size(); ++j) {
                v.push_back(v1[j]);
            }
        }
    }

    cout << an.size() << '\n';
    for (auto &par: an) {
        cout << par.first+1 << ' ' << par.second+1 << '\n';
    }
    return 0;
}
