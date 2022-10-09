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