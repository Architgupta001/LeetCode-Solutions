#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.length()%2!=0){
            return false;
        }
        
        for(int i=0;i<s.length();i++){
            char x=s[i];
            
            if(x=='(' || x=='[' || x=='{'){
                st.push(x);
            }
            else{
                if(st.size()>=1){
                if((st.top()=='('&& x==')') ||            
                    (st.top()=='{' && x=='}')||
                   (st.top()=='[' && x == ']') ){
                    st.pop();
                }
                else{
                    return false;
                }
        }
                else{
                    return false;
                }
            }
        }
    if(st.empty()){
            return true;
        }
    else{
        return false;
        }
    }
};
