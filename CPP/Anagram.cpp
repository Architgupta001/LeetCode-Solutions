// Same characters with different Arrangements

#include <iostream>
#include <string.h>
using namespace std;

int anagram(char *str1, char *str2)
{
      if (strlen(str1) == strlen(str2))
      {

            int hash[26] = {0};

            for (int i = 0; i < strlen(str1); i++)
            {
                  hash[str1[i] - 97]++;
            }
            for (int i = 0; i < strlen(str2); i++)
            {
                  hash[str2[i] - 97]--;

                  if (hash[str2[i] - 97] < 0)
                  {
                        return 0;
                  }
            }
            return 1;
      }
      else
      {
            return 0;
      }
}

int main()
{
      char str1[10], str2[15];
      cout << "Enter the String 1 and String 2 :";
      cin >> str1 >> str2;

      if (anagram(str1, str2))
      {
            cout << "Strings are Anagram ";
      }
      else
      {
            cout << "Not Anagram !";
      }
}
