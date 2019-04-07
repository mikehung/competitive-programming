#include <bits/stdc++.h>

using namespace std;

int n, an;
map<int, int> cnt;

int num(int n)
{
    int an = 0;
    for (auto &kv: cnt) if (kv.second >= n-1) ++an;
    return an;
}

void factor(int n)
{
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            ++cnt[i];
            n /= i;
        }
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
    int an = num(75) +
             num(15) * (num(5)-1) +
             num(25) * (num(3)-1) +
             (num(5) * (num(5)-1) * (num(3)-2)) / 2;
    cout << an << endl;
    return 0;
}
