class Solution {
public:
    string convertToBase7(int n) {
        bool is_negative = false;
        string val = "";
        if (n == 0) {
            val = "0";
            return val;
        }
        if (n < 0) {
            n = n * (-1);
            is_negative = true;
        }
        while (n > 0) {
            val = to_string(n % 7) + val;
            n /= 7;
        }
        if (is_negative) {
            val = "-" + val;
        }
        return val;
    }
};
