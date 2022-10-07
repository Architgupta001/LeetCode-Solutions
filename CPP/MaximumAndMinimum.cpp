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

      int max = arr[0], min = arr[0];
      for (int i = 1; i < n; i++)
      {
            if (arr[i] < min)
            {
                  min = arr[i];
            }
            else if (arr[i] > max)
            {
                  max = arr[i];
            }
      }

      cout << "Maximum is " << max << " Mininmum  is " << min;
}
