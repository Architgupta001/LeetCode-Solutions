from queue import PriorityQueue as PQ

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        pq = PQ()
        pq.put(1)
        for i in range(1, n):
            k = pq.get()
            print(k)
            if k % 3 != 0 and k % 5 != 0:
                pq.put(k*2)
            if k % 5 != 0:
                pq.put(k*3)
            pq.put(k*5)
        
        return pq.get()