#include <bits/stdc++.h>
using namespace std;
 
int BracketsBal(string s)
{
    stack<char> temp;
    for (int i = 0; i < s.length(); i++) {
        if (temp.empty()) {
             
            temp.push(s[i]);
        }
        else if ((temp.top() == '(' && s[i] == ')') || (temp.top() == '{' && s[i] == '}') || (temp.top() == '[' && s[i] == ']')) {
            temp.pop();
        }
        else {
            temp.push(s[i]);
        }
    }
    if (temp.empty()) {
         
        return 1;
    }
    return 0;
}
 
int main()
{
    string s = "{([{}])}()()[({})]";
 
     if (BracketsBal(s))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
