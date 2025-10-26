# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

        
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        l = []
        size = k

        while head != None:
            l.append(head.val)
            head = head.next

        del head
        i = 0
        dummy = ListNode()
        head = dummy

        while i < len(l):

            temp = l[i:k]
            
            if len(temp) == size :
                temp.reverse()

            for j in temp:
                head.next = ListNode()
                head = head.next
                head.val = j

            i = k
            k = k + size
            del temp
        del head

        return dummy.next
