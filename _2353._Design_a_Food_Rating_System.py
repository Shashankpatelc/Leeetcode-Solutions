import heapq
from typing import List

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.foodinfo = {}
        self.cusine_list = {}

        for i in range(len(foods)):
            self.foodinfo[foods[i]] = (cuisines[i],ratings[i])
        
            if cuisines[i] not in self.cusine_list:
                self.cusine_list[cuisines[i]] = []
            heapq.heappush(self.cusine_list[cuisines[i]],(-ratings[i],foods[i]))
            
    def changeRating(self, food: str, newRating: int) -> None:
        self.foodinfo[food] = (self.foodinfo[food][0],newRating)
        heapq.heappush(self.cusine_list[self.foodinfo[food][0]],(-newRating,food))

    def highestRated(self, cuisine: str):
        heap = self.cusine_list[cuisine]
        while heap:
            rate ,food = heap[0]
            if -rate == self.foodinfo[food][1]:
                return food
            heapq.heappop(heap)


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)