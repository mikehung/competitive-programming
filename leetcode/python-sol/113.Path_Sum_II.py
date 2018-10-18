#!/usr/bin/env python

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if not root: return []
        if not root.left and not root.right and root.val == sum: return [[root.val]]
        path = []
        for p in self.pathSum(root.left, sum-root.val) + self.pathSum(root.right, sum-root.val):
            path.append([root.val] + p)
        return path

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution1:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def helper(node, sum, path, paths):
            if not node:
                return
            path.append(node.val)
            if not node.left and not node.right and sum == node.val:
                paths.append(path)
            else:
                helper(node.left, sum-node.val, path, paths)
                helper(node.right, sum-node.val, path, paths)
            path.pop()

        paths = []
        helper(root, sum, [], paths)
        return paths
