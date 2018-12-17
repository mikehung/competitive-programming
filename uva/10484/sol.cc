#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

bool is_prime(int x)
{
    for (int i = 2; i*i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

map<int, int> get_factors(int n)
{
    map<int, int> cnt;
    for (auto &prime: primes) {
        if (prime * prime > n) break;
        int c = 0;
        while (n % prime == 0) {
            ++c;
            n /= prime;
        }
        cnt[prime] = c;
    }
    if (n > 1) {
        cnt[n] = 1;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < 123; ++i) {
        if (is_prime(i))
            primes.push_back(i);
    }
    long long ans = 0;
    int N, D;
    while (cin >> N >> D && (N || D)) {
        ans = 1;
        if (N == 0 || N == 1) {
            if (D == 1) ans = 1;
            else ans = 0;
        } else {
            map<int, int> cntN, cntD = get_factors(D);
            for (int i = 2; i <= N; ++i) {
                for (auto &kv: get_factors(i)) {
                    cntN[kv.first] += kv.second;
                }
            }
            for (auto &kv: cntD) {
                cntN[kv.first] -= kv.second;
            }
            bool flag = true;
            for (auto &kv: cntN) {
                if (kv.second < 0) {
                    flag = false;
                    break;
                }
                ans *= kv.second+1;
            }
            if (!flag) {
                ans = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
