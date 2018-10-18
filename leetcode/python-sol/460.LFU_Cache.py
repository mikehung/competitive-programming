#!/usr/bin/env python

class FreqNode(object):
    def __init__(self, freq=None):
        self.freq = freq
        self.queue = Node()
        self.prev = self
        self.next = self

class Node(object):
    def __init__(self, key=None, value=None, freq_node=None):
        self.key = key
        self.value = value
        self.prev = self
        self.next = self
        self.freq_node = freq_node

class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.size = 0
        self.cache = dict()
        self.freq_queue = FreqNode()

    def add_to_queue(self, prev, curr, next):
        prev.next = curr
        next.prev = curr
        curr.prev = prev
        curr.nect = next

    def key_freq_plue_one(self, key):
        node = self.cache[key]
        freq_node = node.freq_node
        if freq_node.freq + 1 == freq_node.next.freq:
            next_freq_node = freq_node.next
        else:
            next_freq_node = FreqNode(freq_node.freq + 1)
            self.add_to_queue(freq_node, next_freq_node, freq_node.next)
        node.freq_node = next_freq_node

        # del in freq_node.queue
        node.next.prev = node.prev
        node.prev.next = node.next

        # if freq_node.queue is empty then delete itself
        if freq_node.queue.next == freq_node.queue.prev == freq_node.queue:
            del freq_node

        # add in next_freq_node.queue
        node.next = next_freq_node.queue.next
        node.prev = next_freq_node.queue
        node.freq_node = next_freq_node
        next_freq_node.queue.next.prev = node
        next_freq_node.queue.next = node


    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.cache:
            return -1
        self.key_freq_plue_one(key)
        return self.cache[key].value


    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if not self.capacity:
            return

        if key in self.cache:
            node = self.cache[key]
            node.value = value
            self.key_freq_plue_one(key)
        else:
            if self.size == self.capacity:
                # delete the lfu items
                lfu = self.freq_queue.next.queue.next

            if self.freq_queue.next.freq == 1:
                freq1_node = self.freq_queue.next
            else:
                freq1_node = FreqNode(1)
                self.add_to_queue(self.freq_queue, freq1_node, self.freq_queue.next)


                self.size -= 1




# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
