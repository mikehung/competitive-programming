#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 200000 + 5;
int n, s, a[NMAX];

int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int mid = n / 2;
    if (a[mid] == s) {
        cout << 0 << '\n';
    } else {
        long long cnt = 0;
        if (a[mid] < s) {
            for (; mid < n && a[mid] < s; ++mid)
                cnt += (long long) s-a[mid];
        } else {
            for (; mid >= 0 && a[mid] > s; --mid)
                cnt += (long long ) a[mid]-s;
        }
        cout << cnt << '\n';
    }

    return 0;
}
// Time: O(), Space: O()
