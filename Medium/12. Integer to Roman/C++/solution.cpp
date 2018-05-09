#include <bits/stdc++.h>

using namespace std;

/**
 * 罗马数字，根据题目意思，实际上是一种多进制数，应该从最低位开始判断是否需要转换
 * 其中10的倍数 I X C M 都作为1使用，V L D 都作为5使用
 * 也就是，对每一位，先判断是否大于5，如果大于5那么减去5之后填上足够的1，再加上对应的5
 * 如果小于5，那直接填上足够的1即可
 * 如果恰好是5，那么直接添加5
*/
string intToRoman(int num)
{
    if (num < 1 || num > 3999)
        return "";
    string ans = "";
    string _1[] = {"I", "X", "C", "M"},
           _5[] = {"V", "L", "D"};
    int count = 0;
    while (num != 0)
    {
        int digit = num % 10;
        num = num / 10;
        switch (digit)
        {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            for (int i = 0; i < digit; ++i)
            {
                ans = _1[count] + ans;
            }
            break;
        case 4:
            ans = _1[count] + _5[count] + ans;
            break;
        case 5:
            ans = _5[count] + ans;
            break;
        case 6:
        case 7:
        case 8:
        {
            string tmp = _5[count];
            for (int i = 0; i < digit - 5; ++i)
            {
                tmp += _1[count];
            }
            ans = tmp + ans;
            break;
        }
        case 9:
            ans = _1[count] + _1[count + 1] + ans;
            break;
        }
        ++count;
    }
    return ans;
}

int main()
{
    while (true)
    {
        int num;
        cin >> num;
        cout << intToRoman(num) << endl;
    }
    return 0;
}