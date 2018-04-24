#include <bits/stdc++.h>

using namespace std;

/**
 * 一位一位的读入输入字符串
 * case ‘ ’：如果之前没有出现过非空格，则继续，否则终止于此
 * case ‘0-9’：对答案 * 10 + 当前数
 * case ‘-’：标记值为负数；若开始转换终止于此
 * case ‘+’：标记值为正数；若开始转换终止于此
 * case other：终止于此
*/
int myAtoi(string str)
{
    long long ans = 0;
    bool startConversion = false, isNeg = false;
    for (auto c : str)
    {
        if (c == ' ')
        {
            if (startConversion)
                break;
        }
        else if (c == '-')
        {
            if (startConversion)
                break;
            startConversion = true;
            isNeg = true;
        }
        else if (c == '+')
        {
            if (startConversion)
                break;
            startConversion = true;
        }
        else if (c >= '0' && c <= '9')
        {
            startConversion = true;
            ans = ans * 10 + (c - '0');
        }
        else
        {
            break;
        }
        if (ans > INT_MAX)
        {
            break;
        }
    }
    if (startConversion == false)
        return 0;
    if (isNeg)
        ans = -ans;
    return ans > INT_MAX ? INT_MAX : (ans < INT_MIN ? INT_MIN : ans);
}

int main()
{
    string str;
    cout << "INT_MIN: " << INT_MIN << endl
         << "INT_MAX: " << INT_MAX << endl
         << "LLONG_MAX: " << LLONG_MAX << endl;
    while (getline(cin, str))
    {
        cout << myAtoi(str) << endl;
    }
    return 0;
}
