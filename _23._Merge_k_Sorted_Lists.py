# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        result = []

        for i in lists:
            while i != None:
                result.append(i.val)
                i = i.next
        
        result.sort()
        head = ListNode()
        reslist = head
        
        for i in result:
            reslist.next = ListNode()
            reslist = reslist.next
            reslist.val = i
        head = head.next
        return head

