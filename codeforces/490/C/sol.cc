#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e6+7;
string pk;
long long a, b, fa[MAX], fb[MAX];

int main()
{
    cin >> pk >> a >> b;
    int n = pk.size();
    long long f10 = 1;
    for (int i = 0; i < n; ++i) {
        fa[i+1] = (fa[i]*10 + pk[i]-'0') % a;
        fb[i+1] = (f10*(pk[n-i-1]-'0')) % b;
        f10 = (f10 * 10) % b;
    }
    for (int i = 0; i < n; ++i) {
        fb[i+1] = (fb[i+1] + fb[i]) % b;
    }
    for (int i = 1; i < n; ++i) {
        if (!fa[i] && !fb[n-i] && pk[i] != '0') {
            cout << "YES\n" << pk.substr(0, i) << '\n' << pk.substr(i) << '\n';
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}
