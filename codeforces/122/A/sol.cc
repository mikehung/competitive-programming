#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

bool lucky(int n)
{
    while (n) {
        if ((n % 10) != 4 && (n % 10) != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 4; i <= 1000; ++i) {
        if (lucky(i) && (n % i) == 0) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
