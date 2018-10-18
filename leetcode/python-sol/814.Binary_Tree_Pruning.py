# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return root
        if not root.left and not root.right:
            return root if root.val else None
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        return root if root.val == 1 or root.left or root.right else None
