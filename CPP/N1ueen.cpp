#include<iostream>
using namespace std;
bool isSafe(int board[][100], int i,int j,int n ){
    int l=i,m=j;
    for(int k=0; k < n ; k++){
        if(board[k][j]==1|| board[i][k]==1){
            return false;
        }
    }
    //check upper right diagonal
    while(i>=0 and j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }
    // check upper left diagonal
    while(l>=0 and m>=0)
{
    if(board[l--][m--]){
        return false;
    }
   
} 
return true;
}


bool Nqueen(int board[][100],int i ,int n){
    //base case
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               // cout<<board[i][j]<<" ";
               board[i][j]==1? cout<<"Q" : cout<<"_ ";

            }
            cout<<endl;
        }
        cout<<endl;
        return false; // true for one config and false for all config
    }

    // recursive case
    //har column or jaao ith row ke
    for(int j=0;j<n;j++){
        //check karlo jis cell par ho waha queen rakhna safe hai ya nhi
        if(isSafe(board,i,j,n)==true){
            board[i][j]=1; // agar safe hai toh rakhdo

            // ab baaki n-1 queen recusion ko pucho usne rkhi hai ya nhi?
            bool kyaBakiPlaceHui=Nqueen(board,i+1,n);
            //agar place ho gyii toh ban gyi baat
            if(kyaBakiPlaceHui==true){
                return true;
            }
            // agar place nhi ho paai toh jo queen jis position pr rakhi thi woh glt hai
            board[i][j]=0;
        }
    }
    return false;// har column pr check karliya 
}

int main(){
    int board[100][100];
    Nqueen(board,0,4);
    return 0;
}