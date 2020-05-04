#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> L;
    long long sum = 0;
    for (int i = 0; i < n; ++i) if (s[i] == 'L') {
        L.push_back(i);
        sum += i;
    }

    int sz = L.size();
    long long mxk = sum - 1ll*sz*(sz-1)/2;
    if (k > mxk) {
        cout << -1 << '\n';
        return 0;
    }

    int left = mxk-k, i = 0;
    vector<vector<int>> an;
    while (k) {
        while (i < sz && L[i] == i) ++i;
        // cerr << "k: " << k << ' ' << i << '\n';
        vector<int> cand;
        for (int j = i; j < sz; ++j) {
            if (j == 0 || L[j-1]+1 < L[j]) {
                cand.push_back(j);
                if (cand.size() >= left+1) break;
            }
        }
        if (cand.empty()) {
            cout << -1 << '\n';
            return 0;
        }
        an.push_back(vector<int>());
        for (auto c: cand) {
            an.back().push_back(L[c]--);
        }
        left -= cand.size()-1;
        --k;
    }

    if (left != 0) {
        cout << -1 << '\n';
        return 0;
    }

    for (auto &v: an) {
        cout << v.size();
        for (auto &x: v) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
    return 0;
}
