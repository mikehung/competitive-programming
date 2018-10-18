#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = n+1; ; ++i) {
        vector<int> a(10);
        int j = i;
        while (j) {
            a[j%10]++;
            j /= 10;
        }
        bool flag = true;
        for (int k = 0; k < 10; ++k) {
            if (a[k] > 1)
                flag = false;
        }
        if (flag) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
