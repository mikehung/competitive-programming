#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 50000;
int n, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    if (!a && !b) {
        for (int i = 0; i < n; ++i)
            cout << 1 << ' ';
        cout << '\n';
        return 0;
    }
    vector<int> nums = {1};
    if (b == 0)
        nums.push_back(1);
    while (b--)
        nums.push_back(nums.back()*2);
    while (a--)
        nums.push_back(nums.back()+1);
    while ((int) nums.size() < n)
        nums.push_back(nums.back());
    bool flag = false;
    for (int i = 0; i < n; ++i) if (nums[i] > MAX)
        flag = true;
    if (flag || (int) nums.size() > n) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i)
        cout << nums[i] << ' ';
    cout << '\n';
    return 0;
}
