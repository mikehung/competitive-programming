#include <bits/stdc++.h>
using namespace std;

struct Operation {
    int type;
    long long x;
    Operation() {}
    Operation(int _type, long long _x): type(_type), x(_x) {}
};

long long m, n, type, x, l, c;
vector<long long> ids;
vector<Operation> ops;

int find(long long x)
{
    int i = upper_bound(ids.begin(), ids.end(), x) - ids.begin() - 1;

    if (ops[i].type == 1) {
        return ops[i].x;
    }

    return find((x - ids[i]) % ops[i].x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long id = 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> type;
        ids.emplace_back(id);
        if (type == 1) {
            cin >> x;
            ops.emplace_back(type, x);
            id++;
        } else {
            cin >> l >> c;
            ops.emplace_back(type, l);
            id += l*c;
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cout << find(x-1) << ' ';
    }
    cout << '\n';

    return 0;
}
