class Solution:
    def twoSum(self, num, target):
        dictMap = {}
        for i, v in enumerate(num):
            if target - v in dictMap:
                return dictMap[target - v] + 1, i + 1
            dictMap[v] = i
print Solution().twoSum([11, 2, 15, 7], 9)
