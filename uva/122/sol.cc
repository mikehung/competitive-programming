#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#ifdef DEBUG
    #define debug(args...)  {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // do nothing
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

unordered_map<string, int> m;

Node *dfs(string path)
{
    if (m.find(path) == m.end())
        return NULL;
    Node *root = new Node(m[path]);
    root->left = dfs(path + "L");
    root->right = dfs(path + "R");
    return root;
}

void level_order(Node *root, vector<int> &ans)
{
    if (!root) return;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node *node = Q.front();
        Q.pop();
        ans.push_back(node->val);
        if (node->left)
            Q.push(node->left);
        if (node->right)
            Q.push(node->right);
        delete(node);
    }
}

void solve()
{
    Node *tree = dfs("");
    vector<int> ans;
    level_order(tree, ans);
    if (ans.size() != m.size()) {
        cout << "not complete\n";
    } else {
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i];
            if (i != ans.size()-1)
                cout << ' ';
        }
        cout << '\n';
    }
}

int main() 
{
    string s, path;
    int pos, val;
    bool flag = true;
    while (cin >> s) {
        s = s.substr(1, s.size()-2);
        if (s == "") {
            if (!flag) {
                cout << "not complete\n";
            } else {
                solve();
                m.clear();
                flag = true;
            }
        } else {
            pos = s.find(',');
            val = stoi(s.substr(0, pos));
            path = s.substr(pos+1);
            if (m.count(path))
                flag = false;
            m[path] = val;
        }
    }
}
