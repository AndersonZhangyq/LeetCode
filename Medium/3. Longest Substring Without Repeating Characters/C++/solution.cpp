#include <bits/stdc++.h>

using namespace std;

/**
 * 动态规划的话也需要判断之前的子串中是否包含新的字符，故放弃
 * 直接从头开始扫描字符串，记录下每个字符出现的位置，记录当前没有重复字符的字符串的起始位置 from
 * 当有两个字符重复时，计算当前字符串的长度（from 到 当前字符所在位置前一个字符所构成的字符串）
 * 和最大长度比较，更新最大长度
 * @@ 更新 from 为 from 和 该字符串前一次出现的后一个位置 两者中的最大值
 * 更新当前字符出现位置为当前位置。
 * @@ 当做到字符串末尾时，需要考虑从 from 到 字符串结尾 这一部分是否构成新的符合条件的字符串，计算当前字符串长度并更新最大长度
 */
int lengthOfLongestSubstring(string s)
{
    int length = s.length();
    if (length <= 1)
        return length;
    map<char, int> pos;
    int max = 1;
    int from = 0;
    pos[s[0]] = 0;
    for (int i = 1; i < length; ++i)
    {
        char cur = s[i];
        if (pos.find(s[i]) == pos.end())
        {
            pos[cur] = i;
        }
        else
        {
            cout << "pos[" << cur << "]= " << pos[cur] << endl;
            int l = i - from;
            cout << "max = " << max << " , l = " << l << endl;
            max = max < l ? l : max;
            from = pos[cur] + 1 > from ? pos[cur] + 1 : from;
            cout << "from = " << from << endl;
            pos[cur] = i;
        }
    }
    int l = length - from;
    max = max < l ? l : max;
    return max;
}

int main()
{
    while (true)
    {
        string s;
        cin >> s;
        cout << lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
