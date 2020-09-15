#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> primes, ok;
int n, resp, tot, cnt;

void ask(char type, int x)
{
    cout << type << ' ' << x << endl;
    if (type == 'B') {
        for (ll j = x; j <= n; j += x) {
            if (ok[j]) {
                ok[j] = false;
                tot--;
            }
        }
    }

    cin >> resp;
}

bool check_tot()
{
    ask('A', 1);
    return resp == tot;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    tot = n;
    ok.assign(n+1, true);
    for (ll i = 2; i <= n; ++i) {
        if (ok[i]) {
            primes.push_back(i);
            for (ll j = i*i; j <= n; j += i) {
                ok[j] = false;
            }
        }
    }
    reverse(primes.begin(), primes.end());

    tot = n;
    ok.assign(n+1, true);

    ll an = 1;
    int lo = 0, hi = primes.size();
    while (lo < hi) {
        while (lo < hi && an * primes[lo] > n) lo++;

        int mid = lo + (hi-lo+1)/2;
        for (int x = lo; x < mid; ++x) {
            ask('B', primes[x]);
        }

        if (!check_tot()) {
            for (int x = lo; x < mid; ++x) {
                ll v = primes[x];
                if (an * v > n) continue;
                while (true) {
                    ask('A', v);
                    if (resp == 0) {
                        an *= v/primes[x];
                        break;
                    }
                    v *= primes[x];
                    if (v > n) {
                        an *= v/primes[x];
                        break;
                    }
                }
            }
        }
        lo = mid;
    }
    cout << 'C' << ' ' << x << endl;

    return 0;
}
