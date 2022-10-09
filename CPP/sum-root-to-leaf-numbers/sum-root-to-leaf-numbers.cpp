/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sum=0;
    void solve(TreeNode* root, int n){
        if(!root) return;
        n=n*10 +root->val;
        if(!root->left && !root->right){
            sum+=n;
            return ;
        }
        solve(root->left,n);
        solve(root->right,n);
        
    }
    
    int sumNumbers(TreeNode* root) {  
        solve(root,0);
            return sum;
    }
};
