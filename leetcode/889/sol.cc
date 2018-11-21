#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) return NULL;
        int n = pre.size();
        map<int, int> ids;
        for (int i = 0; i < n; ++i) {
            ids[post[i]] = i;
        }
        map<int, TreeNode*> parents;
        TreeNode *root = new TreeNode(pre[0]);
        TreeNode *cur = root;
        for (int i = 1; i < n; ++i) {
            while (ids[cur->val] < ids[pre[i]]) {
                cur = parents[cur->val];
            }
            TreeNode *&nxt = cur->left ? cur->right : cur->left;
            nxt = new TreeNode(pre[i]);
            parents[pre[i]] = cur;
            cur = nxt;
        }
        return root;
    }
};

void dump(TreeNode *root)
{
    if (root) {
        dump(root->left);
        cout << root->val << ' ';
        dump(root->right);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> pre = {1,2,4,5,3,6,7}, post = {4,5,2,6,7,3,1};
    // [1,2,3,4,5,6,7]
    TreeNode *root = Solution().constructFromPrePost(pre, post);
    dump(root);
    return 0;
}
