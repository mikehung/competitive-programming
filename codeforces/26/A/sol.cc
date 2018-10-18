#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 3123;
int n;
vector<int> primes;
vector<bool> p(MAX, true), ap(MAX, true);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    p[0] = p[1] = false;
    for (int i = 2; i <= MAX; ++i) {
        if (p[i]) {
            primes.push_back(i);
            for (int j = i*i; j < MAX; j += i)
                p[j] = false;
        }
    }
    set<int> S;
    int np = primes.size();
    for (int i = 0; i < np; ++i) {
        for (int j = 0; j < np; ++j) {
            if (i == j) continue;
            int k = primes[i];
            while (1LL * k * primes[j] <= n) {
                S.insert(k*primes[j]);
                k *= primes[i];
            }
        }
    }
    cout << S.size() << '\n';
    return 0;
}
