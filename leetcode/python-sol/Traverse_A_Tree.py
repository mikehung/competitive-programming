class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preorder(root, ans=[]):
    if root:
        ans.append(root.val)
        preorder(root.left)
        preorder(root.right)
    return ans


def preorder_iterative(root):
    ans, stack = [], []
    stack.append(root)
    while stack:
        node = stack.pop()
        if node:
            ans.append(node.val)
            stack.append(node.right)
            stack.append(node.left)
    return ans


def inorder(root, ans=[]):
    if root:
        inorder(root.left)
        ans.append(root.val)
        inorder(root.right)
    return ans


def inorder_iterative(root):
    node, ans, stack = root, [], []
    while node:
        stack.append(node)
        node = node.left

    while stack:
        node = stack.pop()
        ans.append(node.val)
        node = node.right
        while node:
            stack.append(node)
            node = node.left
    return ans


def postorder(root, ans=[]):
    if root:
        postorder(root.left)
        postorder(root.right)
        ans.append(root.val)
    return ans


def postorder_iterative(root):
    ans, stack = [], []
    stack.append(root)
    while stack:
        node = stack.pop()
        if node:
            stack.append(node.right)
            stack.append(node.left)
            ans.append(node.val)
    return ans


tree = TreeNode('F',
        TreeNode('B',
         TreeNode('A'),
         TreeNode('D',
          TreeNode('C'),
          TreeNode('E')
         )
        ),
        TreeNode('G',
         None,
         TreeNode('I',
          TreeNode('H'),
          None
         )
        )
       )

print('preorder: {}'.format('->'.join(preorder(tree))))
print('preorder (iter): {}'.format('->'.join(preorder_iterative(tree))))
print('inorder: {}'.format('->'.join(inorder(tree))))
print('inorder (iter): {}'.format('->'.join(inorder_iterative(tree))))
print('postorder: {}'.format('->'.join(postorder(tree))))
print('postorder (iter): {}'.format('->'.join(postorder_iterative(tree))))
