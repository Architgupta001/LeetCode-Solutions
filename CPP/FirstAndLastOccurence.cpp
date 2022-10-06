// This method is Binary Search TC:logN(best). Further we can do it by Linear search TC
// Using Vectors we can use Pair.

#include <iostream>
using namespace std;

// 1. By using Binary Search
 int firstOccurence(int arr[], int n, int key)
 {
       int low = 0, high = n - 1;
       int mid = (low + high) / 2;
       int index = -1;

      while (low <= high)
      {
            if (arr[mid] == key)
            {
                  index = mid;
                  high = mid - 1;
            }
            else if (arr[mid] > key)
            {
                  high = mid - 1;
            }
            else
            {
                  low = low = mid + 1;
            }
            mid = (low + high) / 2;
      }
      return index;
}

int lastOccurence(int arr[], int n, int key)
{
      int start = 0, end = n - 1;
      int mid = (start + end) / 2;

      int index = -1;

      while (start <= end)
      {
            if (arr[mid] == key)
            {
                  index = mid;
                  start = mid + 1;
            }
            else if (arr[mid] > key)
            {
                  end = mid - 1;
            }
            else
            {
                  start = mid + 1;
            }
            mid = (start + end) / 2;
      }
      return index;
}

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

      int key;
      cout << "Enter the Key element :";
      cin >> key;

      cout << "First Occurecen is " << firstOccurence(arr, n, key) << " and Last occurence is " << lastOccurence(arr, n, key);
}

// 2...This is By Linear Search O(n)
// int main()
// {
//       int n;
//       cout << "Enter the Size of the Array :";
//       cin >> n;

//       int arr[n];

//       cout << "Enter the Elements of the Array :";
//       for (int i = 0; i < n; i++)
//       {
//             cin >> arr[i];
//       }

//       int key, firstOccurence = -1, lastOccurence = -1;
//       cout << "Enter the Key Element :";
//       cin >> key;

//       for (int i = 0; i < n; i++)
//       {
//             if (arr[i] != key)
//             {
//             }
//             else if (firstOccurence == -1)
//             {
//                   firstOccurence = i;
//             }
//             else
//             {
//                   lastOccurence = i;
//             }
//       }
//       cout << "First Occurence is " << firstOccurence << " and Last Occurence is " << lastOccurence;
// }

// 3. This is Brute Force O(n^2)
//  int main()
//  {
//        int n;
//        cout << "Enter the Size of the Array :";
//        cin >> n;

//       int arr[n];

//       cout << "Enter the Elements of the Array :";
//       for (int i = 0; i < n; i++)
//       {
//             cin >> arr[i];
//       }

//       int key;
//       cout << "Enter the Key element :";
//       cin >> key;

//       int firstOccurence = -1, lastOccurence = -1;

//       // 1 2 3 3 3 4 and key 3
//       for (int i = 0; i < n; i++)
//       {
//             if (arr[i] == key)
//             {
//                   firstOccurence = i;
//                   int j = i;
//                   while (arr[i] == arr[j])
//                   {
//                         j++;
//                   }
//                   lastOccurence = j - 1;
//                   i = j - 1;
//             }
//       }
//       cout << "First Occurence is " << firstOccurence << " Last Occurence is " << lastOccurence;
// }
