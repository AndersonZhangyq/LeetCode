class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        if length <= 1:
            return list()
        all = dict()
        for i in range(length):
            all[nums[i]] = i
        i = 0
        while i < length:
            left = target - nums[i]
            if left in all.keys() and i != all[left]:
                a = i
                b = all[left]
                if a > b:
                    t = a
                    a = b
                    b = t
                return [a, b]
            i += 1


nums = input('number: \n')
nums = [int(x) for x in nums.split(' ')]
target = int(input('target: '))
ans = Solution().twoSum(nums, target)
print('{} {}'.format(ans[0], ans[1]))
