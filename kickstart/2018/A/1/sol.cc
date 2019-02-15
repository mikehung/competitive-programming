#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string n, s, l;
        cin >> n;

        int sz = n.size();
        bool odd = false;
        for (int i = 0; i < sz; ++i) {
            if (odd) {
                s += '8';
                l += '0';
            } else {
                s += n[i];
                l += n[i];
                if ((n[i]-'0') & 1) {
                    odd = true;
                    s[i]--;
                    if (n[i] != '9') {
                        l[i]++;
                    } else {
                        l[i] = '0';
                        bool carry = true;
                        for (int j = l.size()-2; j >= 0; --j) {
                            if (l[j] == '8') {
                                l[j] = '0';
                            } else {
                                l[j] += 2;
                                carry = false;
                                break;
                            }
                        }
                        if (carry) {
                            l = "2" + l;
                        }
                    }
                }
            }
        }

        // cerr << s << ' ' << l << endl;
        long long N = stoll(n), sn = stoll(s), ln = stoll(l);
        cout << "Case #" << i << ": " << min(ln-N, N-sn) << '\n';
    }
    return 0;
}
