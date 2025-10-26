# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        if head == None:
            return head

        if head.next == None:
            return head

        temp = head.next
        head.next = temp.next
        temp.next = head
        head = head.next
        res = temp
        r = res

        while head != None:
            temp = head.next
            if temp == None or head == None:
                break
                
            head.next = temp.next
            temp.next = head
            head = head.next
            res = res.next
            res.next = temp
            res = res.next

        del head
        del temp
        del res
        return r
        