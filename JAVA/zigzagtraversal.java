// ! problem-link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
       
    List<List<Integer>> res=new ArrayList<>();
        if(root==null) return res;
        boolean flag=true;
        Queue<TreeNode> q=new LinkedList<TreeNode>();
        q.offer(root);
        while(!q.isEmpty()){
            int levelNum=q.size();
            List<Integer> level=new LinkedList<>();
            for(int i=0; i<levelNum; i++){
                if(q.peek().left!=null) q.offer(q.peek().left);
                if(q.peek().right!=null) q.offer(q.peek().right);
                if(flag)
                level.add(q.poll().val);
                else
                    level.add(0,q.poll().val);
            }
           res.add(level);
           flag=!flag;
        }
        return res;        
    }
}