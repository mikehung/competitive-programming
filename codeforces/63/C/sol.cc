#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 14;
string strs[MAX];
int n, a[MAX], b[MAX];
bool visit[MAX];
vector<string> ans, all_strs;

void gen_strs(string cur = "")
{
    if (cur.size() == 4) {
        all_strs.push_back(cur);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            gen_strs(cur+to_string(i));
            visit[i] = false;
        }
    }
}

bool check(string &str)
{
    bool res = true;
    int x, y;
    for (int i = 0; i < n; ++i) {
        x = y = 0;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (strs[i][k] == str[j]) {
                    if (k == j) {
                        ++x;
                    } else {
                        ++y;
                    }
                    break;
                }
            }
        }
        if (a[i] != x || b[i] != y) {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> strs[i] >> a[i] >> b[i];
    }
    gen_strs();
    for (string &str : all_strs) {
        if (check(str)) {
            ans.push_back(str);
            if (ans.size() > 1) {
                puts("Need more data");
                return 0;
            }
        }
    }
    if (ans.empty()) {
        puts("Incorrect data");
    } else {
        cout << ans[0] << '\n';
    }

    return 0;
}
