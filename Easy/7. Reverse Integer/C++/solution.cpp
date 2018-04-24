#include <bits/stdc++.h>

using namespace std;

/**
 * 注意审题！
 * 题目比较简单，只是要把一个数反转过来，只需要从个位开始一位位取然后再加到反转后的新数上
 * 每次加的时候，有 新数 = 10 * 新数 + 某一位，这样可以保证他没有前导零
 * @@ 由于有溢出风险，题目中要求对溢出的数据返回 0！
 * 简单的方式就是用一个比 int 范围更大的类型，来判断是否超过INT_MAX 和 INT_MIN
*/
int reverse(int x)
{
    if (x == 0)
        return x;
    bool isNeg = false;
    if (x < 0)
    {
        x = -x;
        isNeg = true;
    }
    long long ans = 0;
    while (x != 0)
    {
        int digit = x % 10;
        x = x / 10;
        ans = 10 * ans + digit;
    }
    if (isNeg)
        ans = -ans;
    return ans > INT_MAX ? 0 : (ans < INT_MIN ? 0 : ans);
}

int main()
{
    int x;
    while (cin >> x)
    {
        cout << reverse(x) << endl;
    }
    return 0;
}
