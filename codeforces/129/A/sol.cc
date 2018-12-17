#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, odd = 0, even = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x & 1)
            ++odd;
        else
            ++even;
        sum += x;
    }
    cout << (sum & 1 ? odd : even) << '\n';
    return 0;
}
