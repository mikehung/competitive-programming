#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++mp[a[i]];
    }
    int an = 0, cn = 0;
    vector<int> nums, cnds;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it == mp.begin()) {
            cn = it->second;
            cnds = {it->first};
        } else {
            if (it->first-1 != prev(it)->first) {
                cn = it->second;
                cnds = {it->first};
            } else {
                cn += it->second;
                cnds.push_back(it->first);
            }
        }

        if (cn > an) {
            an = cn;
            nums = cnds;
        }

        if (it->second == 1) {
            cnds = {it->first};
            cn = 1;
        }
    }
    cout << an << endl;
    for (int i = 0; i < (int) nums.size(); ++i) {
        int left;
        if (i == 0 || i == nums.size()-1) {
            left = 0;
        } else {
            left = 1;
        }
        while (mp[nums[i]] != left) {
            cout << nums[i] << ' ';
            --mp[nums[i]];
        }
    }
    for (int i = nums.size()-2; i >= 1; --i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}
