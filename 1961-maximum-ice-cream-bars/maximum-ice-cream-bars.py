class Solution:
    def maxIceCream(self, costs: list[int], coins: int) -> int:
        listt = sorted(costs)
        sum = 0
        for i in range(0,len(listt)):
            if coins >= listt[i]:
                coins -= listt[i]
                sum += 1
        
        return sum