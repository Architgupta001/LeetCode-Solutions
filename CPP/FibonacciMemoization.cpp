// Printing Just n term , if u want to print till n then make fn void and use cout inside fn.

#include <iostream>
using namespace std;

int fib[100];

int fibonacci(int n)
{
      if (n < 2)
      {
            fib[n] = n;
            return n;
      }
      else
      {
            if (fib[n - 1] == -1)
            {
                  fib[n - 1] = fibonacci(n - 1);
            }
            if (fib[n - 2] == -1)
            {
                  fib[n - 2] = fibonacci(n - 2);
            }
      }
      return fib[n - 1] + fib[n - 2];
}
int main()
{
      int n;
      cin >> n;
      for (int i = 0; i <= n; i++)
      {
            fib[i] = -1;
      }
      cout << fibonacci(n);
}

// Tc O(n) , this is called Memoization and it is solution of Excessive Recursion
