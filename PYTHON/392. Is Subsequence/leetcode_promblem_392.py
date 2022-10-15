class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        index = 0
        count = len(s)
        if count == 0:
            if len(s) == 0:
                return True
            else:
                return False
        
        for i in t:
            if index < len(s) and i == s[index]:
                print("i:", i, "s:", s[index], "index:", index)
                count -= 1
                index += 1
        if count > 0:
            return False
        return True