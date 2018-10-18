class Solution:
    def bestRotation(self, A):
        n = len(A)
        score = [0]*n
        for i, v in enumerate(A):
            score[(i+1)%n] += 1
            score[(i-v+1)%n] -= 1

        k = 0
        for i in range(1, len(score)):
            score[i] += score[i-1]
            if score[i] > score[k]:
                k = i
        return k

A = [2, 3, 1, 4, 0]
print(Solution().bestRotation(A))

A = [1, 3, 0, 2, 4]
print(Solution().bestRotation(A))
