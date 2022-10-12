class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        '''
        the key of this problem is, for a specific grid,
        find out its max left/right boundry,
        so the first thought is to scan from left to right and 
        right to left to get them.
        leftMaxHeights[x] represents max left boundary height for index x
        rightMaxHeights[x] represents max right boundary height for index x
        please note that len(leftMaxHeights) and len(rightMaxHeights)
        are both equal to len(height)-2 since the beginning and ending block
        cannot contain any water per problem description
        '''
        leftMaxHeights = []
        rightMaxHeights = []
        
        totalLen = len(height)
        if (totalLen < 3):
            return 0
        
        maxLeftHeight = height[0]
        for i in range(1, totalLen-1):
            leftMaxHeights.append(maxLeftHeight)
            if maxLeftHeight < height[i]:
                maxLeftHeight = height[i]            
        maxRightHeight = height[-1]
        for i in range(totalLen-2, 0, -1):
            rightMaxHeights.insert(0, maxRightHeight)
            if maxRightHeight < height[i]:
                maxRightHeight = height[i]
        
        waterVol = 0
        for i in range(1, totalLen-1):
            possibleVol = min(leftMaxHeights[i-1], rightMaxHeights[i-1]) - height[i]
            if possibleVol > 0:
                waterVol += possibleVol
        return waterVol
