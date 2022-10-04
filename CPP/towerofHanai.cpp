#include<iostream>
using namespace std;

void toh(int n , char src, char helper, char des){
    //base case
    if(n==0){
        return;
    }

    //recursive case
    toh(n-1,src,des,helper); // help n des ko interchange kiya hai
    cout<<"taking disc"<< n <<"from"<<src<<"to"<<des<<endl;
    toh(n-1,helper,src,des); // src n helper ko swap kiya hai
}
int main(){
    int n;
    cin>>n;
    toh(n,'A','B','C');


    return 0;
}