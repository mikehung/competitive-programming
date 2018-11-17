#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+123;
int n, a[MAX], b, id[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        id[a[i]] = i;
    }
    int cur = -1;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (id[b] < cur)
            cout << 0 << ' ';
        else {
            cout << id[b] - cur << ' ';
            cur = id[b];
        }
    }
    cout << '\n';
    return 0;
}
