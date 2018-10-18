#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int NMAX = 200005, DIGIT = 11;
int A[NMAX];
int Div[NMAX][DIGIT];
unordered_map<int, int> cnt[DIGIT];

int main()
{
    int n, k, d, x;
    scanf("%d %d", &n, &k);
	for (int i = 0; i < DIGIT; ++i)
		cnt[i].max_load_factor(.25);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        Div[i][0] = A[i] % k;
        ++cnt[0][Div[i][0]];
        for (d = 1; d < DIGIT; ++d) {
            Div[i][d] = (Div[i][d-1] * 10LL) % k;
            ++cnt[d][Div[i][d]];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        d = to_string(A[i]).size();
        x = (k - Div[i][0]) % k;
        if (cnt[d].count(x))
            ans += cnt[d][x];
        if ((Div[i][d] + Div[i][0]) % k == 0)
            --ans;
    }
    cout << ans << '\n';
}
// Time: O(), Space: O()
