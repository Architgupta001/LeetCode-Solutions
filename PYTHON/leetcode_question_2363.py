class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        rlt = []
        items1_check = [0 for i in range(len(items1))]
        items2_check = [0 for i in range(len(items2))]
        for i in range(len(items1)):
            weight = items1[i][1]
            for j in range(len(items2)):
                if items1[i][0] == items2[j][0]:
                    weight += items2[j][1]
                    items1_check[i] = 1
                    items2_check[j] = 1
                    rlt.append([items1[i][0], weight])
                    break
            
        for i in range(len(items1_check)):
            if items1_check[i] == 0:
                rlt.append(items1[i])
        for i in range(len(items2_check)):
            if items2_check[i] == 0:
                rlt.append(items2[i])
        rlt.sort()
        print(rlt)

        return rlt