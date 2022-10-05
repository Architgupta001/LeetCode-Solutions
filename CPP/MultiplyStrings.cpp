// Leetcode question 43. Multiply Strings 

#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    string ans(m + n, '0');
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = sum % 10 + '0';
            ans[i + j] += sum / 10;
        }
    }
    for (int i = 0; i < m + n; i++) {
        if (ans[i] != '0') {
            return ans.substr(i);
        }
    }
    return "0";
}

int main()
{
    string num1, num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;
    cout<<"Product of both numbers: "<<multiply(num1, num2)<<endl;
    return 0;
}
