class BSTIterator {
    private:
    stack<TreeNode*> st;
    bool flag=true;
public:
    BSTIterator(TreeNode* root, bool check) {
        flag = check;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(flag==true){
            pushAll(temp->right);
        }
        else{
            pushAll(temp->left);
        }
        return temp->val;
    }
    
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(flag==true){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr){
            return false;
        }
        
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        
        int i=l.next();
        int j=r.next();
        
        while(i<j){
            if(i+j < k){
                i = l.next();
            }
            else if(i+j > k){
                j = r.next();
            }
            else{
                return true;
            }
        }
        
        return false;
        
    }
};