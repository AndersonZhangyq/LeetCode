#include <bits/stdc++.h>

using namespace std;

/**
 * 动态规划求解
 * dp[i，j] 代表从第i个字符开始，到第j个字符结束的字符串是否是回文子串
 *     dp[i,j] = true           当 s[i...j] 是一个回文字符串
 *             = false          当 s[i...j] 不是一个回文字符串
 * 判断从 j 开始到当前位置 i 的子串是否是回文：
 * 首先判断在 j = i - 1 位置上的字符是否与当前字符相同，如果是则 dp[j][i] = true;
 * 接着，j = i - 2，依此递减直到 j = 0，从 j 到当前位置的子串是否是回文
 * 判断 s[i] 和 s[j] 是否相等，如果相等，检查中间的子串是否是回文，如果是则 dp[j][i] = true
 * 当前子串长度为 j - i + 1，如果大于最大长度则更新最大长度，记录当前子串
*/
string longestPalindrome(string s)
{
	string all_p[1000];
	int length = s.length();
	if (length <= 1)
		return s;
	bool dp[1000][1000];
	memset(&dp, 0, sizeof(dp));
	int max_length = 1;
	string longest = string() + s[0];
	dp[0][0] = true;
	all_p[0] = string() + s[0];
	for (int i = 1; i < length; ++i)
	{
		dp[i][i] = true;
		int j = i - 1;
		if (j >= 0 && s[i] == s[j])
		{
			dp[j][i] = true;
			int l = i - j + 1;
			if (max_length < l)
			{
				max_length = l;
				longest = s.substr(j, l);
			}
		}
		--j;
		while (j >= 0)
		{
			if (s[i] == s[j] && (j + 1 < length && i - 1 >= 0 && j + 1 <= i - 1 && dp[j + 1][i - 1] == true))
			{
				dp[j][i] = true;
				int l = i - j + 1;
				if (max_length < l)
				{
					max_length = l;
					longest = s.substr(j, l);
				}
			}
			--j;
		}
	}
	return longest;
}

int main()
{
    while (true)
    {
        string s;
        cin >> s;
        cout << longestPalindrome(s) << endl;
    }
    return 0;
}
