#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int board[][9],int i , int j, int no, int n){
    ////row and column me nhi hone chahiye 
    for(int k=0;k<n;k++){
        if(board[i][k]==no || board[k][j]==no){
            return false;
        }
    }
    //lets uterate iver the smallerbox
    n=sqrt(n); // n=3
    int si=(i/n)*n;
    int sj=(j/n)*n;

    for(int k=si;k<si+n;++k){
        for(int l=sj;l<sj+n;++l){
            if(board[i][j]==no){
                return false;
            }
        }
    }
    return true;
}




bool sudukoSolver(int board[][9], int i, int j ,int n){
    //base case
if(i==n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return true;
}


    // recursive case

    if(j==n){
        return sudukoSolver(board,i+1,0,n);
    }
    if(board[i][j]!=0){
        return sudukoSolver(board,i,j+1,n);
    }
    for(int no=1;no<=n;no++){
        if(isSafe(board,i,j,no,n)){
            board[i][j]=no;
            bool kyaBaakiSolveHua=sudukoSolver(board,i,j+1,n);
            if(kyaBaakiSolveHua==true){
                return true;
            }
            board[i][j]=0; //backtracking
        }
    }
    return false;
}

int main(){
     int mat[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

        sudukoSolver(mat,0,0,9);
    return 0;
}