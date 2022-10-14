class Solution:
    def countBits(self, n: int) -> List[int]:
        rlt = []
        for i in range(n+1):
            temp = str(bin(i))
            rlt.append(temp.count('1'))

        return rlt