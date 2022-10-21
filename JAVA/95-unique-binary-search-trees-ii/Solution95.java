/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution95 {
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> result = new ArrayList<>();
        boolean[] used = new boolean[n];
        if(n == 0) return result;
        generateTrees(n, result, used, null);
        return result;
    }
    private void generateTrees(int n, List<TreeNode> result, boolean[] used, TreeNode root){
        if(n == 0){
            result.add(copyTree(root));
            return;  
        } 
        else{
            for(int i = 0; i < used.length; i++){
                if(used[i]) continue;
                used[i] = true;
                if(n == used.length){
                    TreeNode tempRoot = new TreeNode(i + 1);
                    generateTrees(n - 1, result, used, tempRoot);
                }else{
                    addTreeNode(root, new TreeNode(i + 1));
                    generateTrees(n - 1, result, used, root);
                    removeNode(root, i + 1);
                }
                used[i] = false;
            }
        }
    }
    private void removeNode(TreeNode root, int val){
        if(root == null) return;
        if(val < root.val){
            if(root.left.val == val){
                root.left = null;
                return;
            }
            removeNode(root.left, val);
        }else{
            if(root.right.val == val){
                root.right = null;
                return;
            }
            removeNode(root.right, val);
        }
    }
    private TreeNode copyTree(TreeNode root){
        if(root == null) return null;
        TreeNode result = new TreeNode(root.val);
        if(root.left != null) result.left = copyTree(root.left);
        if(root.right != null) result.right = copyTree(root.right);
        return result;
    }
    private void addTreeNode(TreeNode root, TreeNode node){
        if(node.val < root.val){
            if(root.left == null)
                root.left = node;
            else
                addTreeNode(root.left, node);
        }
        else{
            if(root.right == null)
                root.right = node;
            else
                addTreeNode(root.right, node);
        }
    }
}
