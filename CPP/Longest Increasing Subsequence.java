class Solution {
    int minCount = Integer.MAX_VALUE;

    public int coinChange(int[] coins, int amount) {
        if (amount <= 0) {
            return 0;
        }

        minCount = Integer.MAX_VALUE;
        dfs(coins, amount, 0);
        return minCount == Integer.MAX_VALUE ? -1 : minCount;
    }

    private int dfs(int[] coins, int remain, int count) {
        if (remain < 0) {
            return -1;
        }

        if (remain == 0) {
            minCount = Math.min(minCount, count);
            return count;
        }
        
        for (int x : coins) {
            dfs(coins, remain - x, count + 1);
        }

        return -1;
    }
}
