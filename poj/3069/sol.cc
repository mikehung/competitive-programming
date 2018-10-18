#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1234;
int R, n, a[MAX];

int main()
{
    while (cin >> R >> n && R != -1 && n != -1) {
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a+n);

        int ans = 0, i = 0, p;
        while (i < n) {
            ++ans;
            p = a[i++];
            while (i < n && a[i] <= p + R) ++i;
            p = a[i-1];
            while (i < n && a[i] <= p + R) ++i;
        }

        cout << ans << '\n';
    }
    return 0;
}
