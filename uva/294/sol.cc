#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

long long int MAX = 1e5+9;
int T, L, R;
vector<int> spf(MAX);
vector<long long> primes;

void sieve()
{
    for (int i = 2; i < MAX; ++i) {
        if (!spf[i]) {
            primes.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; primes[j]*i < MAX; ++j) {
            spf[primes[j]*i] = primes[j];
            if ((i % primes[j]) == 0)
                break;
        }
    }
}

int get_factors(long long n)
{
    map<int, int> factors;
    for (int i = 0; i < (int) primes.size() && primes[i]*primes[i] <= n; ++i) {
        while ((n % primes[i]) == 0) {
            n /= primes[i];
            factors[primes[i]]++;
        }
    }
    if (n > 1)
        factors[n]++;
    int cnt = 1;
    for (auto &kv : factors) {
        cnt *= kv.second+1;
    }
    return cnt;
}

int main()
{
    sieve();
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &L, &R);
        int mx = 0, num = 0, cnt;
        for (int i = L; i <= R; ++i) {
            cnt = get_factors(i);
            if (cnt > mx) {
                mx = cnt;
                num = i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, R, num, mx);
    }
    return 0;
}
