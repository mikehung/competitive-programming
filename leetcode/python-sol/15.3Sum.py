#!/usr/bin/env python

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3: return []

        nums.sort()
        if nums[0] > 0 or nums[-1] < 0: return []
        result = []
        prev = None
        for k, v in enumerate(nums):
            if v == prev: continue
            prev = v
            i, j = 0, len(nums)-1
            while i < j:
                if i == k:
                    i += 1
                    continue
                elif j == k:
                    j -= 1
                    continue
                if nums[i] > 0 and nums[j] > 0 and nums[k] > 0:
                    break

                if nums[i] < 0 and nums[j] < 0 and nums[k] < 0:
                    break

                s = nums[i] + nums[j] + nums[k]
                if s == 0:
                    r = sorted([nums[i], nums[j], nums[k]])
                    if r not in result:
                        result.append(r)
                    i += 1
                    j -= 1
                elif s > 0:
                    j -= 1
                else:
                    i += 1

        return result

nums = [9,-9,4,12,12,0,-14,-7,10,-1,11,-10,-3,2,-9,0,8,-9,-5,-1,10,5,13,-5,-9,-12,9,-3,10,10,-10,4,8,1,-7,-2,-14,-6,6,11,8,-6,9,13,11,7,-10,-4,14,0,3,1,-10,-7,3,-12,-3,-11,0,-8,-15,5,3,8,13,11,13,-15,-9,4,3,6,5,-11,-4,-6,4,1,5,-5,-13,-7,11,-8,2,-1,-12,14,3,3,13,-5,-14,-7,11,14,-11,9,6,-13,-9,-13,1,11,-9,12,-10,2,-1,3,12,-7,3,0,0,12,6,3,3,-13,14,1,-3]
print(Solution().threeSum(nums))
print(len(Solution().threeSum(nums)))
Solution().threeSum(nums)
