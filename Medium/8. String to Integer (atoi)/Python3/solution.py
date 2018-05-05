class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        startConversion = False
        ans = 0
        isNeg = False
        for s in str:
            if s == " ":
                if startConversion == False:
                    continue
                else:
                    break
            elif s.isdigit():
                ans = ans * 10 + int(s)
                startConversion = True
            elif s == "+":
                if startConversion:
                    break
                startConversion = True
                continue
            elif s == "-":
                if startConversion:
                    break
                startConversion = True
                isNeg = True
            else:
                break
            if ans > 2 ** 31:
                break
        if isNeg:
            ans *= -1
        return -2 ** 31 if ans < -2 ** 31 else (2 ** 31 - 1 if ans > 2 ** 31 - 1 else ans)

        
str_ = input("Enter string: ")
print(Solution().myAtoi(str_))