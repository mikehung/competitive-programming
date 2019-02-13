#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int n = 100;

    // generate random permutation for 1~100
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);
    shuffle(perm.begin(), perm.end(), rng);

    for (auto &x: perm) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
