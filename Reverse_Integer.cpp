int reverse(int number) {
        
        int result  = 0;
        while( number != 0) {
            
            int digit = number % 10;
            
            if( (result > INT_MAX/10) || (result < INT_MIN/10)) {
                return 0;
            }
            
            result = (result * 10) + digit;
            number = number / 10;
            
        }
        return result;
    }
