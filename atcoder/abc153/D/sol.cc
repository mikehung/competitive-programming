#include <bits/stdc++.h>

using namespace std;

map<long long, long long> mp;

long long dfs(long long h)
{
    if (h == 1) return 1;
    if (!mp.count(h)) {
        mp[h] = 1 + 2ll * dfs(h/2);
    }
    
    return mp[h];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long h;
    cin >> h;
    cout << dfs(h) << '\n';
    return 0;
}
