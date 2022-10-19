 class Solution
 {
     public:
         int get(char x)
         {
             if (x == 'M') return 1000;
             if (x == 'D') return 500;
             if (x == 'C') return 100;
             if (x == 'L') return 50;
             if (x == 'X') return 10;
             if (x == 'V') return 5;
             return 1;
         }

     int romanToInt(string s)
     {
         int ans = 0;
         for (int i = 0; i < s.length();)
         {
             if (get(s[i]) >= get(s[i + 1]))
             {
                 ans += get(s[i]);
                 i++;
             }
             else
             {
                 int y = get(s[i + 1]) - get(s[i]);
                 ans += y;
                 i += 2;
             }
         }
         return ans;
     }
 };
