#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 1; i <= 11; ++i)
        cnt[i] = 4;
    cnt[10] += 4+3+4;
    cout << cnt[n-10] << '\n';
    return 0;
}
