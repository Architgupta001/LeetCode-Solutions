class Solution {
public:
    int count = 0;  

    void dfs(TreeNode* root, int maxSoFar) {
        if(root) {

            if(root->val >= maxSoFar) count++;

            dfs(root->left, max(maxSoFar,root->val));

            dfs(root->right, max(maxSoFar,root->val));

        }

    }

    int goodNodes(TreeNode* root) {

        dfs(root, INT_MIN);

        return count;

    }
};
