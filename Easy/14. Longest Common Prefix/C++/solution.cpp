#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int length = strs.size();
    if (length == 0)
        return "";
    if (length == 1)
        return strs[0];
    string ans = "";
    string origin = strs[0];
    int o_length = origin.length();
    for (int i = 0; i < o_length; ++i){
        char cur = origin[i];
        for(int j = 1; j < length; ++j){
            if (i >= strs[j].length())
                return ans;
            if (cur != strs[j][i])
                return ans;
        }
        ans += cur;
    }
    return ans;
}

int main()
{
    vector<string> strs;
    while(true){
        strs.clear();
        int num;
        cin >> num;
        for(int i = 0; i < num; ++i){
            string s;
            cin >> s;
            strs.push_back(s);
        }
        cout << longestCommonPrefix(strs) << endl;
    }
    return 0;
}
