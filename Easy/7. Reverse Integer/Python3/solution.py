class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        reversed = 0
        isNeg = False
        if x < 0:
            isNeg = True
            x = -x
        while x != 0:
            digit = x % 10
            reversed = 10 * reversed + digit
            x = int(x / 10)
        if isNeg:
            x = -x
        return 0 if reversed > 2 ** 31 - 1 or reversed < -2 ** 31 else reversed

x = int(input("Enter number: "))
print(Solution().reverse(x))     