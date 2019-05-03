#include <bits/stdc++.h>

using namespace std;

int n, q;
string s;
vector<int> a;

void read()
{
    for (int i = n; i < 2*n; ++i) {
        cin >> a[i];
    }
}

void build()
{
    for (int i = n-1; i; --i) {
        a[i] = min(a[i*2], a[i*2+1]);
    }
}

void update(int i, int v)
{
    for (a[i+=n] = v; i > 1; i /= 2) {
        a[i/2] = min(a[i], a[i^1]);
    }
}

int query(int l, int r)
{
    int an = INT_MAX;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) an = min(an, a[l++]);
        if (r & 1) an = min(an, a[--r]);
    }
    return an;
}

vector<int> parse()
{
    int v = 0;
    vector<int> vec;
    for (int i = 6; i < s.size(); ++i) {
        if (s[i] == ',' || s[i] == ')') {
            vec.push_back(v-1);
            v = 0;
        } else {
            v = v*10 + (int)(s[i]-'0');
        }
    }
    return vec;
}

void shift()
{
    vector<int> vec = parse();
    int first = a[vec[0]+n];
    for (int i = 0; i < vec.size()-1; ++i) {
        update(vec[i], a[vec[i+1]+n]);
    }
    update(vec.back(), first);
}

void query()
{
    vector<int> vec = parse();
    cout << query(vec[0], vec[1]+1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    a.resize(2*n);
    read();
    build();
    while (q--) {
        cin >> s;
        if (s[0] == 's') {
            shift();
        } else {
            query();
        }
    }
    return 0;
}
