#include <bits/stdc++.h>

using namespace std;


const int BITS = 64;
long long N, K;
vector<bool> k(BITS);
vector<int> cnt(BITS);
vector<long long> pw(BITS);

vector<bool> get_bits(long long x)
{
    vector<bool> v(BITS);
    for (int i = 0; i < BITS && x; ++i) {
        if (x & 1) v[i] = 1;
        x /= 2;
    }
    reverse(v.begin(), v.end());
    return v;
}

void solve()
{
    int put;
    bool match = true;
    long long ans = 0;
    for (int i = 0; i < BITS; ++i) {
        if ((N-cnt[i]) <= cnt[i]) {
            put = 0;
            if (k[i]) match = false;
        } else {
            if (!match || k[i])
                put = 1;
            else
                put = 0;
        }
        ans += pw[i] * (put ? (N-cnt[i]) : cnt[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[BITS-1] = 1;
    for (int i = BITS-2; i; --i) {
        pw[i] = 2ll * pw[i+1];
    }

    cin >> N >> K;
    k = get_bits(K);

    long long a;
    for(int i = 0 ; i < N ; i++){
        cin >> a;
        vector<bool> bits = get_bits(a);
        for (int i = 0; i < BITS; ++i) {
            cnt[i] += bits[i];
        }
    }
    solve();
    return 0;
}
