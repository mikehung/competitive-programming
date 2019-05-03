#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;

int trans(int v)
{
    if (v == 0) return v;
    else if (v > 0) return 1;
    return -1;
}

void read()
{
    a.clear();
    a.resize(2*n);
    for (int i = n; i < 2*n; ++i) {
        cin >> a[i];
        a[i] = trans(a[i]);
    }
}

void build()
{
    for (int i = n-1; i; i--) a[i] = a[2*i] * a[2*i+1];
}

void modify(int i, int v)
{
    for (a[i+=n] = trans(v); i > 1; i /= 2) a[i/2] = a[i] * a[i^1];
}

int query(int l, int r)
{
    int an = 1;
    for (l += n, r += n; l < r; l/=2, r/=2) {
        if (l&1) an *= a[l++];
        if (r&1) an *= a[--r];
    }
    return an;
}

void calc()
{
    read();
    build();
    char ch;
    int a, b, an;
    while (k--) {
        cin >> ch >> a >> b;
        if (ch == 'C') {
            modify(a-1, b);
        } else {
            an = query(a-1, b);
            cout << "-0+"[an+1];
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> k) {
        calc();
    }
    return 0;
}
