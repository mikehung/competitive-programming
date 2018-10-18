class Solution:
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        if not S:
            return [0, 0]
        line, width = 1, 0
        for c in S:
            w = widths[ord(c) - ord('a')]
            if width + w > 100:
                line += 1
                width = w
            else:
                width += w
        return [line, width]



def test(widths, S):
    print(Solution().numberOfLines(widths, S))

widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S="abcdefghijklmnopqrstuvwxyz"
test(widths, S)

widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"
test(widths, S)

widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = ""
test(widths, S)
