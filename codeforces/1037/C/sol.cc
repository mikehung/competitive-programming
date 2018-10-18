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
    vector<int> diff;
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
            diff.push_back(i);
    int cnt = diff.size();
    for (int i = 1; i < diff.size(); ++i) {
        if (diff[i-1]+1 == diff[i] && a[diff[i-1]] != a[diff[i]]) {
            --cnt;
            ++i;
        }
    }

    cout << cnt << '\n';

    return 0;
}
// Time: O(), Space: O()
