// Leetcode question 54. Spiral Matrix 

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
    int dir = 0;
    int top = 0, bot = m-1, left = 0, right = n-1;
    while(top<=bot && left<=right)
    {
        if(dir==0)
        {
            for(int i=left; i<=right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            dir = 1;
        }
        else if(dir==1)
        {
            for(int i=top; i<=bot; i++)
                ans.push_back(matrix[i][right]);
            right--;
            dir = 2;
        }
        else if(dir==2)
        {
            for(int i=right; i>=left; i--)
                ans.push_back(matrix[bot][i]);
            bot--;
            dir = 3;
        }
        else if(dir==3)
        {
            for(int i=bot; i>=top; i--)
                ans.push_back(matrix[i][left]);
            left++;
            dir = 0;
        }
    }
    return ans;
}

int main() {
    int m,n;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    vector<vector<int>> mat (m, vector<int>(n));
    cout<<"Enter elements of the matrix in row-wise order: "<<endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>mat[i][j];
        }
    }
    vector<int> ans = spiralOrder(mat);
    cout<<"All the elements of the matrix in spiral order is: ";
    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}