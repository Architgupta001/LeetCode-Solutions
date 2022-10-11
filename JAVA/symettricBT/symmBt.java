class Solution {
    public boolean isSymmetric(TreeNode root) {
         
        
        
        boolean result = same(root.left, root.right);
        
        return result;
        
        
    }
    
    public boolean  same(TreeNode p, TreeNode q){
        
        if(p == null && q == null) return true;
        if(p== null || q== null)  return false;
        
        return((p.val == q.val) && same(p.left, q.right) && same(p.right,q.left));
        
        
    } 
     
}