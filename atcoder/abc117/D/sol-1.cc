#include <bits/stdc++.h>

using namespace std;


const int BITS = 64;
long long N, K;
vector<vector<bool>> v;
vector<bool> k(BITS);
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
    bool match = true;
    long long ans = 0;
    for (int i = 0; i < BITS; ++i) {
        long long cnt = 0;
        for (int j = 0; j < N; ++j) if (v[j][i]) ++cnt;
        if ((N-cnt) <= cnt) {
            // put 0
            ans += pw[i] * cnt;
            if (k[i]) match = false;
        } else {
            // put 1
            if (!match || k[i])
                ans += pw[i] * (N-cnt);
            else
                ans += pw[i] * cnt;
        }
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
        v.push_back(get_bits(a));
    }
    solve();
    return 0;
}
