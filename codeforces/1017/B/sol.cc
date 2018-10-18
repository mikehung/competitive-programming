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

int main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    ll n1 = 0, n01 = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            ++n1;
        } else {
            if (b[i] == '1')
                ++n01;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == '0') {
            if (a[i] == '0')
                ans += n1;
            else
                ans += n01;
        }    
    }
    cout << ans << '\n';

	return 0;
}
// Time: O(), Space: O()
