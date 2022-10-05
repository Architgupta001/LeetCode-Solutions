// Pivot element means the Element About which Rotation is taking place.

#include <iostream>
using namespace std;

int pivotElement(int arr[], int n)
{
      int s = 0, e = n - 1;
      int mid = (s + e) / 2;

      while (s < e)
      {
            if (arr[mid] > arr[0])
            {
                  s = mid + 1;
            }
            else
            {
                  e = mid;
            }
            mid = (s + e) / 2;
      }
      return s;
}

int main()
{
      int n;
      cout << "Enter the Size of the Array :";
      cin >> n;

      int arr[n];
      cout << "Enter the ELements of the Array(Pivot must be there) :";
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      cout << "The Pivot Element Index is " << pivotElement(arr, n);
}
