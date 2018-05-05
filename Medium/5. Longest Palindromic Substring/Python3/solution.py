class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        if length <= 1:
            return s
        dp = [[False] * length for i in range(length)]
        maxLength = 1
        longest = s[0]
        for i in range(length):
            dp[i][i] = True
            if i - 1 < 0:
                continue
            if s[i-1] == s[i]:
                dp[i - 1][i] = True
                if (2 > maxLength):
                    maxLength = 2
                    longest = s[i - 1:i + 1]
            j = i - 2
            while (j >= 0 and j < i):
                if s[j] == s[i] and dp[j + 1][i - 1] == True:
                    dp[j][i] = True
                    if (i - j + 1 > maxLength):
                        maxLength = i - j + 1
                        longest = s[j:i + 1]
                j -= 1
        return longest


while True:
    s = input("Enter the string:\n")
    print(Solution().longestPalindrome(s))
