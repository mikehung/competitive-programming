#!/usr/bin/env python

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def __init__(self):
        self.list = None
        self.back = None

    def addNode(self, val):
        node = ListNode(val)

        if not self.back:
            self.list = node
            self.back = node
        else:
            self.back.next = node
            self.back = node

    def printList(self, list):
        node = list
        n = []
        while node:
            n.append(str(node.val))
            node = node.next
        print(', '.join(n))

    def getList(self):
        return self.list

    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        # 0, n, 1, n-1, 2, n-2,....
        l = []
        node = head
        while node:
            l.append(node)
            node = node.next

        if len(l) < 3:
            return head

        prev = None
        i, j = 0, len(l)-1
        while i < j:
            if prev:
                prev.next = l[i]
            l[i].next = l[j]
            prev = l[j]
            i, j = i+1, j-1

        if i == j:
            if prev:
                prev.next = l[i]
            l[i].next = None
        else:
            if prev:
                prev.next = None
        return head

sol =  Solution()
for i in range(6):
    sol.addNode(i)
sol.printList(sol.list)
sol.reorderList(sol.list)
sol.printList(sol.list)
