#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int n;

void paint(int x) {
    int v = n-x;
    while (v--)
        cout << "  ";
    cout << 0;
    for (int i = 1; i <= x; ++i) {
        cout << ' ' << i;
    }
    for (int i = x-1; i >= 0; --i) {
        cout << ' ' << i;
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        paint(i);
    }

    for (int i = n-1; i >= 0; --i) {
        paint(i);
    }
    return 0;
}
