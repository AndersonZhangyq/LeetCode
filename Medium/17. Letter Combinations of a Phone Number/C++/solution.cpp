#include <bits/stdc++.h>

using namespace std;

map<char, vector<string>> dialer = {{'2', {"a", "b", "c"}},
                                  {'3', {"d", "e", "f"}},
                                  {'4', {"g", "h", "i"}},
                                  {'5', {"j", "k", "l"}},
                                  {'6', {"m", "n", "o"}},
                                  {'7', {"p", "q", "r", "s"}},
                                  {'8', {"t", "u", "v"}},
                                  {'9', {"w", "x", "y", "z"}}};

/**
 * 依次取出每一个数字，找寻对应的所有字母，将之前所保存的所有部分答案都分别加上这些字母。
*/
vector<string> letterCombinations(string digits)
{
    int size = digits.length();
    vector<string> ans;
    if (size < 1)
        return ans;
    for(int i = 0; i < size; ++i){
        auto letter = dialer[digits[i]];
        if (i == 0){
            ans = letter;
        }else{
            vector<string> tmp_ans, tmp = ans;
            for(auto l : letter){
                for(auto t : tmp){
                    tmp_ans.push_back(t + l);
                }
            }
            ans = tmp_ans;
        }
    }
    return ans;
}

int main()
{
    while(true){
        string digits;
        cin >> digits;
        vector<string> ans = letterCombinations(digits);
        for(auto a : ans){
            cout << a << endl;
        }
    }
    return 0;
}
