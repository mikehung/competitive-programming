#include <bits/stdc++.h>

using namespace std;

int n, an;
vector<int> vec;
map<int, int> cnt;
set<tuple<int, int, int>> s;

void check(vector<int> v1, vector<int> v2)
{
    for (int i = 0; i < (int) v1.size(); ++i) if (cnt[v1[i]] < v2[i])
        return;
    if (v1.size() == 3) {
        if (v1[1] > v1[2]) swap(v1[1], v1[2]);
        s.insert(make_tuple(v1[0], v1[1], v1[2]));
    } else {
        ++an;
    }
}

void calc()
{
    for (auto x: vec) {
        check({x}, {74});
        for (auto y: vec) if (x != y) {
            check({x, y}, {2, 24});
            check({x, y}, {4, 14});
            for (auto z: vec) if (x != z && y != z) {
                check({x, y, z}, {2, 4, 4});
            }
        }
    }
}

void factor(int n)
{
    for (int i = 2; i <= n; ++i) {
        int v = 0;
        while (n % i == 0) {
            ++v;
            n /= i;
        }
        if (v) cnt[i] += v;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        factor(i);
    }
    for (auto &kv: cnt) if (kv.second > 1) {
        vec.push_back(kv.first);
    }
    calc();
    cout << an + s.size() << endl;
    return 0;
}
