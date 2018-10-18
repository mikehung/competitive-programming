from icecream import ic


class Solution:
    def numSubarrayBoundedMax(self, A, L, R):
        count = 0
        submax, min_lt, min_in, max_in = float('-inf'), float('inf'), float('inf'), float('-inf')
        for i in range(len(A)):
            if submax is None or A[i] > submax:
                submax = A[i]
            if not (L <= submax <= R):
                submax, min_lt, min_in, max_in = float('-inf'), float('inf'), float('inf'), float('-inf')
                ic(i, A[i], 'B', count)
                continue
            if L <= A[i]:
                max_in = max(max_in, i)
                min_in = min(min_in, i)
                bound = min(min_lt, min_in)
                count += i-bound+1
            elif A[i] < L:
                min_lt = min(min_lt, i)
                if min_in != float('inf'):
                    count += i-min(min_lt, min_in)
            ic(i, A[i], 'L' if L <= A[i] else 'E', min_in, min_lt, max_in, count)

        return count


A = [2, 3, 1, 5, 7, 3]
L, R = 3, 5
# print(Solution().numSubarrayBoundedMax(A, L, R))


A = [1, 2, 1, 4, 3, 2, 4, 3, 2]
L, R = 2, 3
A = [2, 1, 4, 3]
L = 2
R = 3
print(A, L, R)
print(Solution().numSubarrayBoundedMax(A, L, R))

A=[73,55,36,5,55,14,9,7,72,52]
L=32
R=69
print(A, L, R)
print(Solution().numSubarrayBoundedMax(A, L, R))

A=[876,880,482,260,132,421,732,703,795,420,871,445,400,291,358,589,617,202,755,810,227,813,549,791,418,528,835,401,526,584,873,662,13,314,988,101,299,816,833,224,160,852,179,769,646,558,661,808,651,982,878,918,406,551,467,87,139,387,16,531,307,389,939,551,613,36,528,460,404,314,66,111,458,531,944,461,951,419,82,896,467,353,704,905,705,760,61,422,395,298,127,516,153,299,801,341,668,598,98,241]
L=658
R=719
print(A, L, R)
print(Solution().numSubarrayBoundedMax(A, L, R))
