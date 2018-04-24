#include <bits/stdc++.h>

using namespace std;

/**
 * 首先负数不可能是回文的
 * 那么对所有的非负数，不大于10的数一定是回文的
 * 其他的数，依次截取每一位上的数，全部截取完后判断是否是回文
*/
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x < 10)
        return true;
    int digits[40];
    memset(&digits, 0, sizeof(digits));
    int count_ = 0;
    while (x != 0)
    {
        int digit = x % 10;
        cout << "Digit: " << digit << "  Count: " << count_ << endl;
        x = x / 10;
        digits[count_] = digit;
        count_++;
    }
    int i, j;
    for (i = 0, j = count_ - 1; i < j; ++i, --j)
    {
        if (digits[i] != digits[j])
            break;
    }
    return digits[i] == digits[j];
}

int main()
{
    int x;
    while(cin >> x){
        cout << isPalindrome(x) << endl;
    }
    return 0;
}
