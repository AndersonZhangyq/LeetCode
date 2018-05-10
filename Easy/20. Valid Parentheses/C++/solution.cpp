#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    stack<char> _s;
    for(char c : s){
        cout << c << " ";
        printf("s.empty(): %d\n", s.empty() ? 1 : 0);
        if (_s.empty()){
            if (c == ')' || c == ']' || c == '}')
                return false;
            else
                _s.push(c);
        }else{
            if (c == ')' || c == ']' || c == '}'){
                char top = _s.top();
                switch(c){
                    case ')':
                        if (top != '(')
                            return false;
                        break;
                    case ']':
                        if (top != '[')
                            return false;
                        break;
                    case '}':
                        if (top != '{')
                            return false;
                        break;
                }
                _s.pop();
            }else{
                _s.push(c);
            }
        }
    }
    return _s.empty();
}

int main()
{
    while(true){
        string s;
        cin >> s;
        cout << isValid(s) << endl;
    }
    return 0;
}
