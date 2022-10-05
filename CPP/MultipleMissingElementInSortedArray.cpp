// Code is for Sorted Array only 

#include <iostream>
using namespace std;

int main()
{
      int n;
      cout << "Enter the Size of the Array :";
      cin >> n;

      int arr[n];
      cout << "Enter the Elements of the Array :";
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      int difference = arr[0] - 0;
      for (int i = 1; i < n; i++)
      {
            if (arr[i] - i != difference)
            {
                  // If this happen means there is some missing element in the Array
                  cout << difference + i << " ";
                  difference = arr[i] - i;
            }
      }
}
