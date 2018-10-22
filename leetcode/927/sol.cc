#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& a) {
        vector<int> not_found = {-1, -1};
        int n = a.size();
        vector<int> cnt(n+1);
        for (int i = n-1; i >= 0; --i) {
            cnt[i] = cnt[i+1];
            if (a[i] == 1) cnt[i]++;
        }
        if (cnt[0] % 3)
            return not_found;
        if (cnt[0] == 0)
            return {0, 2};
        int p = cnt[0] / 3;
        vector<int> seg(6, -1);
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 3*p)
                seg[5] = i;
            if (cnt[i] == 2*p+1)
                seg[4] = i;
            if (cnt[i] == 2*p)
                seg[3] = i;
            if (cnt[i] == p+1)
                seg[2] = i;
            if (cnt[i] == p)
                seg[1] = i;
            if (cnt[i] == 1)
                seg[0] = i;
        }
        int m = n - seg[0] - 1;
        seg[2] += m;
        seg[4] += m;
        if (seg[2] >= seg[1] || seg[4] >= seg[3])
            return not_found;
        for (int i = 0; i < n - seg[1]; ++i) {
            if (a[i+seg[1]] != a[i+seg[3]] || a[i+seg[1]] != a[i+seg[5]])
                return not_found;
        }
        return {seg[4], seg[2]+1};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a, b;

    a = {1, 0, 1, 0, 1};
    b = Solution().threeEqualParts(a);
    cout << b[0] << ' ' << b[1] << '\n';

    a = {1, 0, 1, 1, 1};
    b = Solution().threeEqualParts(a);
    cout << b[0] << ' ' << b[1] << '\n';

    a = {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0};
    b = Solution().threeEqualParts(a);
    cout << b[0] << ' ' << b[1] << '\n';

    a = {0, 0, 0};
    b = Solution().threeEqualParts(a);
    cout << b[0] << ' ' << b[1] << '\n';

    return 0;
}
