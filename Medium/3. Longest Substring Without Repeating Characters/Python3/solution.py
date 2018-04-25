
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if length <= 1:
            return length
        all_letter = {}
        max_length = 1
        from_ = 0
        for i in range(length):
            if s[i] in all_letter.keys():
                l = i - from_
                max_length = max_length if max_length > l else l
                from_ = from_ if from_ > all_letter[s[i]] + 1 else all_letter[s[i]] + 1
                all_letter[s[i]] = i
            else:
                all_letter[s[i]] = i
        max_length = max_length if  max_length > length - from_ else length - from_
        return max_length

s = input("Enter String:\n")
print(Solution().lengthOfLongestSubstring(s))