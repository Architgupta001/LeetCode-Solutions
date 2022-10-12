#include <iostream>
using namespace std;

int main()
{
      string str;
      int count = 0;
      cout << "Enter the String :";
      getline(cin, str);

      int hash[26] = {0};

      for (int i = 0; i < str.size(); i++)
      {
            hash[str[i] - 97]++;
      }
      for (int i = 0; i < 26; i++)
      {
            if (hash[i] == 0)
            {
                  count++;
            }
      }
      if (count == 0)
      {
            cout << "Pangram ";
      }
      else if (count > 2)
      {
            cout << "Not a Pangram but can be a lipogram ";
      }
      else
      {
            cout << "Pangrammatic lipogram ";
      }
}
