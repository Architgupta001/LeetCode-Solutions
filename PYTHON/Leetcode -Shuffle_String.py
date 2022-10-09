class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        result = ['']*len(s)
        for index,char in enumerate(s):
            result[indices[index]] = char
        return "".join(result)