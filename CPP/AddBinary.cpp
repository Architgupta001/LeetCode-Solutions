// Leetcode question 67. Add Binary

#include <iostream>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int apos = a.size()-1;
    int bpos = b.size()-1;
    int adigit = 0, bdigit = 0, carry = 0;
    
    while(apos>=0 || bpos>=0 || carry==1)
    {
        adigit = bdigit = 0;
        
        if(apos>=0)
            adigit = a[apos--] == '1';
        if(bpos>=0)
            bdigit = b[bpos--] == '1';
        
        result =  char(adigit ^ bdigit ^ carry + '0') + result;
        carry = adigit + bdigit + carry >=2;
    }
    
    return result;
}

int main() {
    string a,b,ans;
    cout<<"Enter first binary string: ";
    cin>>a;
    cout<<"Enter second binary string: ";
    cin>>b;
    ans = addBinary(a,b);
    cout<<"Sum of both binary numbers is: "<<ans<<endl;
    return 0;
}