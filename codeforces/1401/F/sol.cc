#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;
vector<ll> a;
vector<bool> flips;

struct Node {
    ll sum;
    bool flip;
    Node *left, *right;
    Node(ll val): sum(val), flip(0), left(NULL), right(NULL) {};
};

struct segtree {
    Node *root;
    int size, level;

    segtree() {
        size = 1<<n;
        level = n;
        root = build(0, size);
    }

    Node *build(int l, int r) {
        if (l+1 == r) {
            return new Node(a[l]);
        }
        Node *node = new Node(0);
        int m = (l+r)/2;
        node->left = build(l, m);
        node->right = build(m, r);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }

    void debug() {
        cerr << "dbg: ";
        queue<pair<Node*, int>> qu;
        qu.push({root, level});
        while (qu.size()) {
            Node *node = qu.front().first;
            int lv = qu.front().second;
            qu.pop();
            cerr << node->sum << ' ';
            if (lv) {
                qu.push({node->left, lv-1});
                qu.push({node->right, lv-1});
            }
        }
        cerr << endl;
    }

    void push_down(Node *node, int level) {
        if (level == 0) return;
        if (node->flip ^ flips[level]) {
            swap(node->left, node->right);
            node->flip = node->flip ^ 1;
        }
    }

    void pop_up(Node *node, int level) {
        if (level == 0) return;
        node->sum = node->left->sum + node->right->sum;
    }

    void update(Node *node, int x, ll v, int l, int r, int level) {
        push_down(node, level);
        if (l+1 == r) {
            node->sum = v;
            return;
        }
        int m = (l+r)/2;
        if (x < m) {
            update(node->left, x, v, l, m, level-1);
        } else {
            update(node->right, x, v, m, r, level-1);
        }
        pop_up(node, level);
    }

    void update(int x, ll v) {
        update(root, x, v, 0, size, level);
    }

    ll query(Node *node, int l, int r, int lx, int rx, int level) {
        push_down(node, level);
        if (r <= lx || rx <= l) return 0;
        if (l <= lx && rx <= r) return node->sum;
        int m = (lx+rx)/2;
        return query(node->left, l, r, lx, m, level-1) +
            query(node->right, l, r, m, rx, level-1);
    }

    ll query(int l, int r) {
        return query(root, l, r, 0, size, level);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    flips.resize(n+1);
    a.resize(1<<n);
    for (auto &it: a) cin >> it;

    segtree st;
    // st.debug();
    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int x, k;
            cin >> x >> k;
            --x;
            st.update(x, k);
        } else if (ty == 2) {
            int k;
            cin >> k;
            for (int i = 0; i < k+1; ++i) flips[i] = flips[i] ^ true;
        } else if (ty == 3) {
            int k;
            cin >> k;
            flips[k+1] = flips[k+1] ^ true;
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            cout << st.query(l, r) << '\n';
        }
        // st.debug();
    }

    return 0;
}
