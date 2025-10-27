# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        


class Solution:
    
    def sort(self,sorted_list,new_Node):
        if sorted_list is None or sorted_list.val >= new_Node.val:
            new_Node.next = sorted_list
            return new_Node
        
        current_Node = sorted_list
        while current_Node.next and current_Node.next.val < new_Node.val:
            current_Node = current_Node.next
            
        new_Node.next = current_Node.next
        current_Node.next = new_Node
        
        return sorted_list
    
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        sorted_list = None
        current_Node = head
        
        while current_Node:
            next_Node = current_Node.next
            sorted_list = self.sort(sorted_list,current_Node)
            current_Node = next_Node
        return sorted_list

