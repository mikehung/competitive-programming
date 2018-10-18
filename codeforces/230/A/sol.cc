#include <bits/stdc++.h>
using namespace std;

const int MAX = 1234;
int s, n, x[MAX], y[MAX], id[MAX];

bool cmp(int i, int j)
{
    return x[i] < x[j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        id[i] = i;
    }
    sort(id, id+n, cmp);
    for (int i = 0; i < n; ++i) {
        if (s <= x[id[i]]) {
            cout << "NO\n";
            return 0;
        }
        s += y[id[i]];
    }
    cout << "YES\n";

    return 0;
}
