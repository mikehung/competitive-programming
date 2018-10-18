# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fast = slow = dummy = ListNode(0)
        dummy.next = head
        for _ in range(n+1):
            fast = fast.next
        while fast:
            fast, slow = fast.next, slow.next
        slow.next = slow.next.next
        return dummy.next

def get_lst():
    root = ListNode(0)
    root.next = ListNode(1)
    root.next.next = ListNode(2)
    return root

def show(root):
    vals = []
    while root:
        vals.append(str(root.val))
        root = root.next
    print(' -> '.join(vals))

for n in range(1, 4):
    root = get_lst()
    show(root)
    root = Solution().removeNthFromEnd(root, n)
    show(root)
