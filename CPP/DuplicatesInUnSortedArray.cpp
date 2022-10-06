#include <iostream>
using namespace std;

// More optimised way using hash or bitset TC:n
// Care :Maxm element must be greater than the total number of elements.

int main()
{
      int n;
      cout << "Enter the SIze of the Array :";
      cin >> n;

      int arr[n];
      cout << "Enter the Elements of the Array :";
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      int max = arr[0];
      for (int i = 1; i < n; i++)
      {
            if (max < arr[i])
            {
                  max = arr[i];
            }
      }

      int bitset[max] = {0};
      for (int i = 0; i < n; i++)
      {
            bitset[arr[i]]++;
      }

      for (int i = 0; i < max; i++)
      {
            if (bitset[i] > 1)
            {
                  cout << i << " occured " << bitset[i] << " times." << endl;
            }
      }
}
