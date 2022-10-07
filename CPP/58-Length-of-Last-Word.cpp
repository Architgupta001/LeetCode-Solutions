#include <iostream>
using namespace std;

// Given a string 's' consisting of words and spaces, return the length of the last word in the string.
int lengthOfLastWord(string s) {
    int i, c=0;
    for(i = s.size()-1 ; i >= 0 ;i--){
        if(s.at(i) != ' ')
            break;
    }
    for(int j = i ; j >= 0 ; j--){
        if(s.at(j) == ' ')
            break;
        c++;
    }
    return c;
}

int main(){
    string s = "   fly me   to   the moon  ";
    cout << "Input : "<< s << endl;
    cout << "Output : " << lengthOfLastWord(s) << endl;
    return 0;
}