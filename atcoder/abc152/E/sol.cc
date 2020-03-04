#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9+7;
int a[10003], cnt[1000003];

long long ppow(long long a, long long n)
{
    if (n == 0) return 1;
    if (n % 2) return a * ppow(a, n-1) % M;
    long long x = ppow(a, n/2);
    return x * x % M;
}

void f(int x)
{
    for (int i = 2; i*i <= x; ++i) if (x % i == 0) {
        int c = 0;
        while (x % i == 0) {
            c++;
            x /= i;
        }
        cnt[i] = max(cnt[i], c);
    }
    if (x > 1) {
        cnt[x] = max(cnt[x], 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f(a[i]);
    }

    long long all = 1;
    for (int i = 2; i < 1000003; ++i) {
        all *= ppow(i, cnt[i]);
        all %= M;
    }

    long long an = 0;
    for (int i = 0; i < n; ++i) {
        an += all * ppow(a[i], M-2);
        an %= M;
    }
    cout << an << endl;

    return 0;
}
