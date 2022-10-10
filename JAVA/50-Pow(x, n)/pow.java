class Solution {
    public double myPow(double x, long n) {
        if(n==0) return 1;
        if(n==1) return x;
        
        long tmpN = (n<0?(-1)*n:n);
        
        double prevPow = myPow(x,tmpN/2);
        if(tmpN%2==1){
            if(n>=0){
                return prevPow*prevPow*x; 
            }else{
                return 1.0/(prevPow*prevPow*x);
            }
        }else{
            if(n>=0){
                return prevPow*prevPow; 
            }else{
                return 1.0/(prevPow*prevPow);
            }
        }
    }
}
