#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int n, fingers;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int f;
        cin >> f;
        fingers += f;
    }
    int ans = 0;
    for (int i = 1; i <= 5; ++i) {
        if ((fingers+i) % (n+1) != 1)
            ++ans;
    }
    cout << ans << '\n';

    return 0;
}
