#include <bits/stdc++.h>

using namespace std;

int n;
string p;
vector<int> p_arr;

vector<int> to_arr(int k)
{
    vector<int> a;
    while (k) {
        a.push_back(k % 10);
        k /= 10;
    }
    return a;
}

vector<int> multiply(const vector<int> &a1, const vector<int> &a2)
{
    int n1 = a1.size(), n2 = a2.size();
    vector<int> ans(n1+n2-1);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            ans[i+j] += a1[i] * a2[j];
        }
    }
    int carry = 0;
    for (int i = 0; i < n1+n2-1; ++i) {
        ans[i] += carry;
        carry = ans[i] / 10;
        ans[i] %= 10;
    }
    if (carry)
        ans.push_back(carry);
    while ((int) ans.size() > 1 && ans.back() == 0)
        ans.pop_back();
    return ans;
}

bool gte(const vector<int> &a1, const vector<int> &a2)
{
    int n1 = a1.size(), n2 = a2.size();
    if (n1 > n2)
        return true;
    if (n2 > n1)
        return false;
    for (int i = n1-1; i >= 0; --i) {
        if (a1[i] != a2[i])
            return a1[i] >= a2[i];
    }
    return true;
}

bool check(int k)
{
    // compute k^n >= p
    vector<int> ans, k_arr = to_arr(k);
    ans.push_back(1);
    for (int i = 0; i < n; ++i) {
        ans = multiply(ans, k_arr);
    }
    return gte(ans, p_arr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> p) {
        p_arr.clear();
        for (int i = (int) p.size()-1; i >= 0; --i) {
            p_arr.push_back(p[i] - '0');
        }
        int lo = 1, hi = 1e9+9, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}
