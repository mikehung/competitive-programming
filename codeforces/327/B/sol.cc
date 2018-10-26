#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void sieve()
{
    const int MAX = 10000;
    vector<bool> is_prime(MAX, true);
    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i*i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < (int) primes.size(); ++i) {
        for (int j = i; j < (int) primes.size(); ++j) {
            if (!n) break;
            long long v = 1LL * primes[i] * primes[j];
            if (v >= (int) 1e7) continue;
            ans.push_back(v);
            n--;
        }
        if (!n) break;
    }
    sort(ans.begin(), ans.end());
    for (auto x: ans)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
