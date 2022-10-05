class Solution {
public:
    map<int, int> terminate;
    bool isHappy(int n) {
        int temp = 0;
        if(n==1){
            return 1;
        }
        while(n!=0){
            temp += pow(n%10, 2);
            n = n/10;
        }
        if(terminate[temp] == 0){
            terminate[temp] = 1;
        } else{
            return 0;
        }
        return isHappy(temp);
    }
};