class Solution:
    def preimageSizeFZF(self, K):
        def get_zeros(n):
            zeros = 0
            i = 5
            while n >= i:
                zeros += n // i
                i *= 5
            return zeros

        lo, hi = 0, 5*K
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if get_zeros(mid) < K:
                lo = mid+1
            else:
                hi = mid
        return 5 if get_zeros(lo) == K else 0


for i in range(1, 30):
    Solution().preimageSizeFZF(i)
