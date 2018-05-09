#include <bits/stdc++.h>
#include <string>

using namespace std;

/**
 * 给一个罗马数字，从最高位开始以此判断，
 * 如果遇到1，那么判断后一个是不是5，如果是，则为4
 *                  后一个是下一个1，则为9
 *                  后一个是1，则依次判断到最后一个1
 * 如果遇到5，那么判断下一个是不是1，如果是，则依次判断到最后一个1
 *                  后一个是其他的，则为5
*/
int romanToInt(string s)
{
    int i = 0, ans = 0;
    int length = s.length();
    while (i < length)
    {
        // printf("i: %d ans: %d\n", i, ans);
        switch (s[i])
        {
        case 'I':
            if (i == length - 1)
            {
                ans += 1;
                ++i;
            }
            else
            {
                if (s[i + 1] == 'V')
                    ans += 4;
                else if (s[i + 1] == 'X')
                    ans += 9;
                else
                {
                    while (i < length && s[i] == 'I')
                    {
                        ans += 1;
                        i++;
                    }
                    continue;
                }
                i += 2;
            }
            break;
        case 'V':
            ans += 5;
            if (s[i + 1] == 'I')
            {
                i++;
                while (i < length && s[i] == 'I')
                {
                    ans += 1;
                    i++;
                }
            }
            else
                ++i;
            break;
        case 'X':
            if (i == length - 1)
            {
                ans += 10;
                ++i;
            }
            else
            {
                if (s[i + 1] == 'L')
                    ans += 40;
                else if (s[i + 1] == 'C')
                    ans += 90;
                else
                {
                    while (i < length && s[i] == 'X')
                    {
                        ans += 10;
                        i++;
                    }
                    continue;
                }
                i += 2;
            }
            break;
        case 'L':
            ans += 50;
            if (s[i + 1] == 'X')
            {
                i++;
                while (i < length && s[i] == 'X')
                {
                    ans += 10;
                    i++;
                }
            }
            else
                ++i;
            break;
        case 'C':
            if (i == length - 1)
            {
                ans += 100;
                ++i;
            }
            else
            {
                if (s[i + 1] == 'D')
                    ans += 400;
                else if (s[i + 1] == 'M')
                    ans += 900;
                else
                {
                    while (i < length && s[i] == 'C')
                    {
                        ans += 100;
                        i++;
                    }
                    continue;
                }
                i += 2;
            }
            break;
        case 'D':
            ans += 500;
            if (s[i + 1] == 'C')
            {
                i++;
                while (i < length && s[i] == 'C')
                {
                    ans += 100;
                    i++;
                }
            }
            else
                ++i;
            break;
        case 'M':
            if (i == length - 1)
            {
                ans += 1000;
                ++i;
            }
            else
            {
                while (i < length && s[i] == 'M')
                {
                    ans += 1000;
                    i++;
                }
            }
            break;
        }
    }
    return ans;
}

int main()
{
    while (true)
    {
        string num;
        cin >> num;
        cout << romanToInt(num) << endl;
    }
    return 0;
}
