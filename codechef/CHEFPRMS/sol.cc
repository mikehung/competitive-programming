#include <bits/stdc++.h>
using namespace std;

const int MAX = 205;
vector<int> primes;
set<int> semi_primes;

void init()
{
    vector<bool> is_prime(MAX, true);
    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i*i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int n = primes.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (primes[i] * primes[j] < MAX)
                semi_primes.insert(primes[i] * primes[j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        bool flag = false;
        for (auto &sp: semi_primes) {
            if (semi_primes.count(x-sp)) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
