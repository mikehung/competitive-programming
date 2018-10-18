#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif


int main()
{
    int n;
    vector<int> action; // try: 1, throw: 2, catch: 3
    int i, beg, end;
    string line, throw_ex, catch_ex, catch_msg;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, line);
        i = 0;
        while (i < (int) line.size() && line[i] == ' ') ++i;
        line = line.substr(i);
        if (line.empty()) continue;

        if (line.substr(0, 2) == "tr") {
            action.push_back(1);
        } else if (line.substr(0, 2) == "th") {
            beg = line.find('(') + 1;
            end = line.find(')') - 1;
            while (line[beg] == ' ') beg++;
            while (line[end] == ' ') end--;
            throw_ex = line.substr(beg, end-beg+1);
            action.push_back(2);
        } else if (line.substr(0, 2) == "ca") {
            // catch ( AE , "AE in line 3" )
            beg = line.find('(') + 1;
            end = line.find(',') - 1;
            while (line[beg] == ' ') beg++;
            while (line[end] == ' ') end--;
            catch_ex = line.substr(beg, end-beg+1);
            beg = line.find('"') + 1;
            end = line.find_last_of('"') - 1;
            catch_msg = line.substr(beg, end-beg+1);
            if (action.back() == 1) {
                action.pop_back();
            } else {
                action.pop_back();
                action.pop_back();
                if (catch_ex == throw_ex) {
                    cout << catch_msg << '\n';
                    return 0;
                }
                action.push_back(2);
            }
        }
    }
    cout << "Unhandled Exception\n";
    return 0;
}
