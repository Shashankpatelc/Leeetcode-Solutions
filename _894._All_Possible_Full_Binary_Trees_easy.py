from typing import List, Optional

# Definition for a binary tree node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        memo = {}

        def calc(n):
            if n in memo:
                return memo[n]

            if n%2 == 0:
                return []

            if n == 1:
                return [TreeNode(0)]
            
            result = []
            for i in range(1,n,2):
                
                left_node = i
                right_node = n - i - 1

                left_tree = calc(left_node)
                right_tree = calc(right_node)

                for left in left_tree:
                    for right in right_tree:
                        root = TreeNode(0,left,right)
                        result.append(root)
            
            memo[n] = result
            return result
        
        return calc(n)
    