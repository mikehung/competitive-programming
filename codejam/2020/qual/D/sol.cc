#include <bits/stdc++.h>

using namespace std;

int B;
char ch;

void ask(int idx, string &an)
{
    cout << idx+1 << endl;
    cin >> ch;
    an[idx] = ch;

    cout << B-idx << endl;
    cin >> ch;
    an[B-idx-1] = ch;
}

void solve()
{
    string an(B, '2');
    int idx = 0;

    for (int round = 0; round < 15; ++round) {
        // cerr << an << endl;
        if (round == 0) {
            ask(idx++, an);
        } else {
            int count = 0;
            vector<bool> action(4, true);
            for (int i = 0; i < idx; ++i) {
                if (an[i] == an[B-i-1]) {
                    cout << i+1 << endl;
                    cin >> ch;
                    if (ch == an[i]) {
                        action[1] = action[2] = false;
                    } else {
                        action[0] = action[3] = false;
                    }
                    count++;
                    break;
                }
            }

            for (int i = 0; i < idx; ++i) {
                if (an[i] != an[B-i-1]) {
                    cout << i+1 << endl;
                    cin >> ch;
                    if (ch == an[i]) {
                        action[0] = action[1] = false;
                    } else {
                        action[2] = action[3] = false;
                    }
                    count++;
                    break;
                }
            }
            if (action[0]) {
                reverse(an.begin(), an.end());
            } else if (action[1]) {
                for (int i = 0; i < idx; ++i) {
                    an[i] = an[i] == '0' ? '1' : '0';
                    an[B-i-1] = an[B-i-1] == '0' ? '1' : '0';
                }
            } else if (action[2]) {
                reverse(an.begin(), an.end());
                for (int i = 0; i < idx; ++i) {
                    an[i] = an[i] == '0' ? '1' : '0';
                    an[B-i-1] = an[B-i-1] == '0' ? '1' : '0';
                }
            }

            if (count == 1) {
                // just skip this ask
                cout << 1 << endl;
                cin >> ch;
            }
        }
        for (int i = 0; i < 4 && idx < B/2; ++i) {
            ask(idx++, an);
        }
        
        if (idx == B/2) {
            cout << an << endl;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int T;
    char ok;
    cin >> T >> B;
    for (int t = 1; t <= T; ++t) {
        solve();
        cin >> ok;
        if (ok == 'N') return 1;
    }
    return 0;
}
