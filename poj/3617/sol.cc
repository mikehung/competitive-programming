#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    char ch;
    string s, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        s += ch;
    }
    int i = 0, j = n-1;
    while (i <= j) {
        int d = 0;
        for (; i+d < j-d; ++d) {
            if (s[i+d] != s[j-d]) {
                break;
            }
        }
        if (i+d < j-d && s[i+d] < s[j-d]) {
            t += s[i++];
        } else {
            t += s[j--];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << t[i];
        if ((i % 80) == 79) cout << '\n';
    }
    if (n % 80) cout << '\n';
    return 0;
}
