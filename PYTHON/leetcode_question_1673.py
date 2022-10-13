class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        rlt = []
        for i in range(len(accounts)):
            result = 0
            for j in range(len(accounts[i])):
                result += accounts[i][j]
            rlt.append(result)
        rlt.sort()

        return rlt[len(rlt) - 1]
        