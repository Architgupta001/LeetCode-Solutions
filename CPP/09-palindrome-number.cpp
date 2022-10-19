class Solution
{
    public:
        bool isPalindrome(int x)
        {
            int n = x;
            int dig;
            double rev = 0;
            while (x > 0)
            {
                dig = x % 10;
                rev = rev *10 + dig;
                x = x / 10;
            }
            if (n == rev) return true; 
            return false;
        }
};
