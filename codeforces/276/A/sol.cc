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
    int n, k, f, t, ans;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> f >> t;
        if (i == 0) {
            ans = (t > k) ? f-t+k : f;
        } else {
            ans = max(ans, (t > k) ? f-t+k : f);
        }
    }
    cout << ans << '\n';
	return 0;
}
// Time: O(n), Space: O(1)
