from typing import List


class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:

        memo = {}

        def calc(current_needs):

            if tuple(current_needs) in memo:
                return memo[tuple(current_needs)]

            if all(x <= 0 for x in current_needs):
                return 0
            
            min_cost = sum([current_needs[i]*price[i] for i in range(len(current_needs))])
            
            for offer in special:
                dis = True
                new_need = []
                
                for i in range(len(current_needs)):
                    if offer[i] <= current_needs[i]:
                        new_need.append(current_needs[i] - offer[i])
                    else:
                        dis = False
                        break
                if dis:
                    min_cost = min(min_cost,offer[-1] + calc(new_need))
            memo[tuple(current_needs)] = min_cost
            return min_cost
        return calc(needs)