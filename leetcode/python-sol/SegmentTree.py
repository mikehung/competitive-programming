#!/usr/bin/env python


class SegmentTree(object):
    def __init__(self, array):
        self.array = array
        self.st = [0 for _ in range(len(array)*2-1)]

    def get_middle(self, sb, se):
        return sb+(se-sb)/2

    def contruct(self):
        def contruct_helper(sb, se, idx):
            # case 1: leaf node => copy the value to st
            if sb == se:
                self.st[idx] = self.array[sb]
            # case 2: inner node => sum the left and right node
            else:
                sm = self.get_middle(sb, se)
                self.st[idx] = contruct_helper(sb, sm, 2*idx+1) +\
                    contruct_helper(sm+1, se, 2*idx+2)

            return self.st[idx]

        sb, se = 0, len(self.array)-1
        contruct_helper(sb, se, 0)

    def update(self, ni, val):
        def update_helper(sb, se, idx, ni, val):
            # using diff to update all node in the range
            if ni < sb or ni > se:
                return
            self.st[idx] += val
            # stop at the leaf node
            if sb == se:
                return

            sm = self.get_middle(sb, se)
            update_helper(sb, sm, 2*idx+1, ni, val)
            update_helper(sm+1, se, 2*idx+2, ni, val)

        sb, se = 0, len(self.array)-1
        if ni < sb or ni > se:
            raise IndexError('{} out of range'.format(ni))

        diff = val - self.array[ni]
        self.array[ni] = val
        update_helper(sb, se, 0, ni, diff)

    def query_sum(self, qb, qe):
        def sum_helper(qb, qe, sb, se, idx):
            # case 1: qb sb se qe (inside the query range)
            if qb <= sb and se <= qe:
                return self.st[idx]
            # case 2: sb se qb qe, qb qe sb se (outside the query range)
            if se < qb or sb > qe:
                return 0
            # case 3: overlapping
            sm = self.get_middle(sb, se)
            return sum_helper(qb, qe, sb, sm, 2*idx+1) + \
                sum_helper(qb, qe, sm+1, se, 2*idx+2)

        sb, se = 0, len(self.array)-1
        if qb > qe or qb < sb or qe > se:
            raise IndexError('{} and {} out of range'.format(qb, qe))

        s = sum_helper(qb, qe, sb, se, 0)
        print('sum for range ({}, {}) is: {}'.format(qb, qe, s))
        return s


array = [2, 1, 7, 3, 1]
st = SegmentTree(array)
st.contruct()
print(array)
print(st.st)
st.query_sum(0, 4)
st.query_sum(0, 0)
st.query_sum(4, 4)
st.query_sum(0, 2)
st.query_sum(3, 4)
# st.update(100, 1)
st.update(0, 5)
print(array)
print(st.st)
st.query_sum(0, 4)
st.query_sum(0, 0)
st.query_sum(4, 4)
st.query_sum(0, 2)
st.query_sum(3, 4)
