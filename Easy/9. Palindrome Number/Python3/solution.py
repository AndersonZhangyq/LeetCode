class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if x < 10:
            return True
        x = str(x)
        i = 0
        j = len(x) - 1
        while i < j:
            if x[i] != x[j]:
                return False
            i += 1
            j -= 1
        return True

x = int(input("Enter number: "))
print(Solution().isPalindrome(x))