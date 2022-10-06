#include <iostream>
using namespace std;

void swapAlternate(int arr[], int n)
{
      for (int i = 0; i + 2 < n; i += 2)
      {
            int temp1 = arr[i];
            arr[i] = arr[i + 2];
            arr[i + 2] = temp1;
      }

      for (int j = 1; j + 2 < n; j += 2)
      {
            int temp2 = arr[j];
            arr[j] = arr[j + 2];
            arr[j + 2] = temp2;
      }
}

int main()
{
      int arr[20], n;

      cout << "Enter Size of Array :";
      cin >> n;

      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      swapAlternate(arr, n);
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }

      return 0;
}
