class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1:
            return s
        s_len = len(s)
        goDown = True
        first = True
        cur_i = 0
        all_letter = [[" " for row_num in range(s_len)] for row_num in range(numRows)]
        row_num = 0
        l = 0
        while True:
            all_letter[row_num][l] = s[cur_i]
            if first:
                first = False
                continue
            if goDown:
                if row_num % numRows == numRows - 1:
                    goDown = False
                    row_num -= 1
                    l += 1
                else:
                    row_num += 1
            else:
                if row_num == 0:
                    goDown = True
                    row_num += 1
                else:
                    row_num -= 1
                    l += 1
            cur_i += 1
            if cur_i == s_len:
                break
        ans = ""
        for row_num in range(numRows):
            for l in all_letter[row_num]:
                if l != " ":
                    ans += str(l)
        return ans


s = input("Enter string: ")
numRows = int(input("Enter number of rows: "))
print(Solution().convert(s, numRows))