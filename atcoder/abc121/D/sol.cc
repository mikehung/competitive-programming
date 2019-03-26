#include <bits/stdc++.h>

using namespace std;

long long calc(long long x)
{
    long long ans = (x & 1) ? 0 : x;
    if (((x+1)/2) & 1) ans |= 1;
    else {
        if (ans & 1) ans--;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    cout << (calc(b) ^ calc(a-1)) << endl;
    return 0;
}
