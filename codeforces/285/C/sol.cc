#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    multiset<int> perm, nums;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        perm.insert(i);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (perm.count(x))
            perm.erase(x);
        else
            nums.insert(x);
    }
    long long cnt = 0;
    for (auto pit = perm.begin(), nit = nums.begin(); pit != perm.end(); ++pit, ++nit) {
        cnt += abs(*pit - *nit);
    }
    cout << cnt << '\n';
    return 0;
}
