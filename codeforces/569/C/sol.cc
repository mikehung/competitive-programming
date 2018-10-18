#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

// const long long MAX = 1e8;
const long long MAX = 1.5e7;
bool p[MAX];
vector<int> primes, palins;
vector<string> ch;

void sieve()
{
    for (long long i = 2; i < MAX; ++i) {
        if (!p[i]) {
            primes.push_back(i);
            for (long long j = i*i; j < MAX; j += i) {
                p[j] = true;
            }
        }
    }
}

void palin(string s, int i, int d)
{
    if (i == (d+1)/2) {
        int j = d&1 ? i-2 : i-1;
        while (j >= 0) s += s[j--];
        palins.push_back(stoi(s));
        return;
    }
    for (int j = 0; j < 10; ++j) {
        palin(s+ch[j], i+1, d);
    }
}

int main()
{
    sieve();
    int a, b, g;
    cin >> a >> b;
    g = __gcd(a, b);
    a /= g;
    b /= g;
    for (int i = 0; i < 10; ++i)
        ch.push_back(to_string(i));
    for (int d = 1; d <= 8; ++d) {
        for (int i = 1; i < 10; ++i) {
            palin(ch[i], 1, d);
        }
    }
    // long long lo = 1, hi = MAX, mid, pr, pl;
    // while (lo < hi) {
    //     mid = lo + (hi-lo+1)/2;
    //     cerr << mid << '\n';
    //     pr = upper_bound(primes.begin(), primes.end(), mid) - primes.begin();
    //     pl = upper_bound(palins.begin(), palins.end(), mid) - palins.begin();
    //     if (b*pr <= a*pl) {
    //         lo = mid;
    //     } else {
    //         hi = mid-1;
    //     }
    // }
    // cerr << primes[lo] << ' ' << palins[lo] << '\n';
    // cout << lo << '\n';

    return 0;
}
