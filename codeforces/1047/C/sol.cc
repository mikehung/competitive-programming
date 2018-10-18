#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1.5*1e7+7;
int n, x, gcd;
bool S[MAX];
vector<long long> a, primes;
map<int, int> cnt;

int __gcd(int a, int b)
{
    if (!b) return a;
    return __gcd(b, a%b);
}

void sieve()
{
    primes.push_back(2);
    for (long long i = 3; i < MAX; i += 2) {
        if (!S[i]) {
            primes.push_back(i);
            for (long long j = i*i; j < MAX; j += i) {
                S[j] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (!i) {
            gcd = x;
        } else {
            gcd = __gcd(gcd, x);
        }
        a.push_back(x);
    }
    for (int i = 0; i < (int) a.size(); ++i) {
        x = a[i] / gcd;
        for (int j = 0; j < (int) primes.size() && primes[j]*primes[j] <= x; ++j) {
            int prime = primes[j];
            if (x % prime == 0) {
                cnt[prime]++;
                while (x % prime == 0) {
                    x /= prime;
                }
            }
        }
        if (x > 1) {
            cnt[x]++;
        }
    }
    int mx = 0;
    for (auto &kv : cnt) {
        mx = max(mx, kv.second);
    }
    if (!mx) {
        cout << -1 << '\n';
    } else {
        cout << n - mx << '\n';
    }

    return 0;
}
