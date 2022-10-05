class Solution {
public:
    void f(TreeNode* root,int level,int depth,int value)
    {
        if(root==NULL) return;
        if(level==depth-1)
        {
            TreeNode* currleft=root->left;
            TreeNode* currright=root->right;
            TreeNode* node=new TreeNode(value);
            TreeNode* node1=new TreeNode(value);
            root->left=node;
            root->right=node1;
            root->left->left=currleft;
            root->right->right=currright;
            return;
        }
        else{
        if(root->left!=NULL)
        f(root->left,level+1,depth,value);
        if(root->right!=NULL)
        f(root->right,level+1,depth,value);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int value, int depth) {
        if(depth==1)
        {
            TreeNode* node=new TreeNode(value);
            node->left=root;
            return node;
        }
        f(root,1,depth,value);
        return root;
    }
};