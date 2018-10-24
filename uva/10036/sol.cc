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

int mod(int a, int m)
{
    int r = ((a % m) + m) % m;
	return r;
}

int main()
{
    int T, N, K, a;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> cnt(K);
        int all = 0, m;
        for (int i = 0; i < N; ++i) {
            cin >> a;
            m = mod(a, K);
            ++cnt[m];
            all += m;
        }
        all = mod(all, K);
        if (all == 0) {
            cout << "Divisible\n";
            continue;
        }
        bool flag = false;
        vector<bool> div(K), ndiv(K);
        div[all] = ndiv[all] = 1;
        for (int i = 0; i < K && !flag; ++i) {
            for (int _ = 0; _ < cnt[i]; ++_) {
                for (int j = 0; j < K; ++j) {
                    if (div[j])
                        ndiv[mod(j-2*i, K)] = 1;
                }
                div = ndiv;
                if (div[0]) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            cout << "Divisible\n";
        else
            cout << "Not divisible\n";
    }
}
// Time: O(), Space: O()
