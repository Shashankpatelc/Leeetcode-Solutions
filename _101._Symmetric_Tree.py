from collections import deque
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        left = root.left
        right = root.right 

        if (not left and not right):
            return True

        if (left and not right) or (not left and right):
            return False

        left_queue = deque()
        right_queue = deque()

        left_queue.append(left)
        right_queue.append(right)

        while left_queue or right_queue:
            left_val = left_queue.popleft()
            right_val = right_queue.popleft()

            if left_val.val != right_val.val:
                return False
            
            if (left_val.left and right_val.right):
                left_queue.append(left_val.left)
                right_queue.append(right_val.right)

            if (left_val.right and right_val.left):
                left_queue.append(left_val.right)
                right_queue.append(right_val.left)

            if (left_val.left and not right_val.right) or (not left_val.left and right_val.right) or (left_val.right and not right_val.left) or (not left_val.right and right_val.left):
                return False
        return True