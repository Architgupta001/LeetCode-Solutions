/* Leetcode Question-> https://leetcode.com/problems/valid-anagram/ */
/* Name: Vidip Ghosh */
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
    public:
    bool isAnagram(string s1,string s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        if(l1!=l2)
        {
            return false;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<l1;i++)
        {
            if(s1[i]!=s2[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;
    if(s.isAnagram(s1,s2))
    {
        cout<<"Two strings are anagram"<<endl;
    }
    else
    {
        cout<<"Not an anagram"<<endl;
    }
}