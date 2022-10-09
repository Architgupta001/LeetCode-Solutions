//Given the root of a binary tree, return the sum of all left leaves.

// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

class Solution {
public:
    int sum  = 0;
    void sll (TreeNode* root, bool isLeft){
        if(!root)
            return;
        if(isLeft && !root->left && !root->right){
            sum += root->val;
            return;
        }
        sll(root->left, true);
        sll(root->right, false);   
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        sll(root, false);
        return sum;
    }
};