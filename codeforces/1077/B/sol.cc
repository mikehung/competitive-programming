#include <bits/stdc++.h>

using namespace std;

const int MAX = 123;
int n, a[MAX];
vector<int> b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n-1; ++i) {
        if (a[i-1] && !a[i] && a[i+1])
            b.push_back(i);
    }
    int ans = b.size();
    for (int i = 1; i < (int) b.size(); ++i) {
        if (b[i] == b[i-1] + 2) {
            ++i;
            --ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
