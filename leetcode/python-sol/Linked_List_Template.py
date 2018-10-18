#!/usr/bin/env python

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
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
