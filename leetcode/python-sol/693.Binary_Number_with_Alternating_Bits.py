class Solution:
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        prev_char = None
        for char in format(n, 'b'):
            if prev_char and prev_char == char:
                return False
            prev_char = char

        return True

for _ in range(12):
    print(_, format(_, 'b'), Solution().hasAlternatingBits(_))
