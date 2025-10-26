# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        Head = ListNode(0)
        tail = Head
        c = 0

        while l1 is not None or l2 is not None or c != 0:
            d1 = l1.val if l1 is not None else 0
            d2 = l2.val if l2 is not None else 0
            
            sum = d1 + d2 + c
            d = sum % 10
            c = sum // 10

            newNode = ListNode(d)
            tail.next = newNode
            tail = tail.next

            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None
        
        res = Head.next
        Head.next = None
        return res
        