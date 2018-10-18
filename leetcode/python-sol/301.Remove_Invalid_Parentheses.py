class Solution:
    def removeInvalidParentheses(self, s):
        def valid(s):
            left = 0
            for c in s:
                if c == '(':
                    left += 1
                elif c == ')':
                    left -= 1
                    if left < 0:
                        return False
            return left == 0

        def helper(s, num_remove):
            if s in memo:
                return memo[s]
            ret = []
            if valid(s):
                if num_remove == self.max_num_remove:
                    ret.append(s)
                else:
                    ret = [s]
                    self.max_num_remove = num_remove
            elif num_remove < self.max_num_remove:
                for i in range(len(s)):
                    if s[i] in '()':
                        ret += helper(s[:i] + s[i+1:], num_remove+1)
            memo[s] = ret
            return ret

        def trim(s):
            l = []
            found_left = False
            for c in s:
                if c == '(':
                    found_left = True
                if found_left or c != ')':
                    l.append(c)
            r = []
            found_right = False
            for c in reversed(l):
                if c == ')':
                    found_right = True
                if found_right or c != '(':
                    r.append(c)
            return ''.join(reversed(r))


        self.max_num_remove = float('inf')
        memo = {}
        s = trim(s)
        return list(filter(lambda _: len(_) == len(s)-self.max_num_remove, set(helper(s, 0)))) or ['']


import time
def test(s):
    print(s)
    beg = time.time()
    r = Solution().removeInvalidParentheses(s)
    print(r, time.time()-beg)


test('()())()')
test('(a)())()')
test(')(')
test('()')
test('n')
test('(a(())()')
test("()(((((((()")
test("(()()()))((")
test("))aaa))s)(()()()))(a((c((")
test("((()))((()(()")
