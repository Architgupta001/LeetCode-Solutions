class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(node,cursum):
            if not node:
                return False
            cursum += node.val
            if not node.left and not node.right:
                return cursum==targetSum
            return dfs(node.left,cursum) or dfs(node.right,cursum)
        return dfs(root,0)