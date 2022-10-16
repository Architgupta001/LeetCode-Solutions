/*Leetcode Question-> https://leetcode.com/problems/valid-parentheses/ */
/*Name: Vidip Ghosh*/
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
    public:
    bool isValid(string s)
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='[')   //Checking for open parenthesis
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty())
                {
                    char top = st.top();
                    if(ch==')' && ch=='(' || ch=='}' && ch=='{' || ch==']' && ch=='[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    cout<<s.isValid(str);
}