#include <bits/stdc++.h>

using namespace std;

/**
 * 直接根据 zigzag 来输出到 vector 中
 * 当在第 0 行时，开始向下；当在最后一行时，向右上，随后重复
 * @@ 当只需要一行时，直接返回当前字符串即可
*/
string convert(string s, int numRows)
{
    int length = s.length();
    if (length <= 1)
        return s;
    if (numRows == 1)
        return s;
    vector<vector<char> > zigzag(numRows, vector<char>(length, ' '));
    int i = 0, j = 0, max_i = 0, max_j = 0;
    bool goDown = true;
    for (int cur = 0; cur < length; ++cur)
    {
        zigzag[i][j] = s[cur];
        max_i = max_i < i ? i : max_i;
        max_j = max_j < j ? j : max_j;
        if (goDown)
        {
            if (i == numRows - 1)
            {
                goDown = false;
                --i;
                ++j;
            }
            else
            {
                ++i;
            }
        }
        else
        {
            if (i == 0)
            {
                goDown = true;
                ++i;
            }
            else
            {
                --i;
                ++j;
            }
        }
    }
    string ans = "";
    for(int k = 0; k <= max_i; ++k){
        for(int l = 0; l <= max_j; ++l){
            if (zigzag[k][l] != ' ')
                ans += zigzag[k][l];
        }
    }
    return ans;
}

int main()
{
    while(true){
        string s;
        cin >> s;
        int numRows;
        cin >> numRows;
        cout << convert(s, numRows) << endl;
    }
    return 0;
}
