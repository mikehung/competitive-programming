#include <bits/stdc++.h>

using namespace std;

bool type(const string &s)
{
    if (s[0] != 'R') return false;
    int c = s.size() - 1;
    while (c > 1 && s[c] != 'C') --c;
    return c > 1;
}

string get_x(const string &s)
{
    int c = s.size() - 1;
    while (c > 1 && s[c] != 'C') --c;
    return s.substr(1, c-1);
}

string get_y(const string &s)
{
    int c = s.size() - 1;
    while (c > 1 && s[c] != 'C') --c;
    return s.substr(c+1);
}

string to_eng(const string &s)
{
    int num = stoi(s);
    string res;
    while (num) {
        --num;
        res = string(1, (num % 26) + 'A') + res;
        num /= 26;
    }
    return res;
}

string get_num1(const string &s)
{
    int res = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        res = 26 * res + (s[i] - 'A') + 1;
    }
    return to_string(res);
}

string get_eng(const string &s)
{
    int p = s.size() - 1;
    while (s[p] >= '0' && s[p] <= '9') --p;
    return s.substr(0, p+1);
}

string get_num(const string &s)
{
    int p = s.size() - 1;
    while (s[p] >= '0' && s[p] <= '9') --p;
    return s.substr(p+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cerr << s << '\n';
        // RXCY
        if (type(s)) {
            string n1 = get_x(s);
            string n2 = get_y(s);
            cout << to_eng(n2) + n1 << '\n';
        } else {
            // BC23
            string eng = get_eng(s);
            string num = get_num(s);
            cerr << eng << ' ' << num << '\n';
            cout << 'R' + num + 'C' + get_num1(eng) << '\n';
        }
    }
    return 0;
}
