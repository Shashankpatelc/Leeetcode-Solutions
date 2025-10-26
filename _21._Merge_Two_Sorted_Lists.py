# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if list1 == None: 
            return list2
        if list2 == None:
            return list1

        dummy = ListNode()
        temp = dummy


        while(list1!=None and list2!=None):
            if list1.val > list2.val:
                temp.next = ListNode()
                temp = temp.next
                temp.val = list2.val
                list2 = list2.next
            else:
                temp.next = ListNode()
                temp = temp.next
                temp.val = list1.val
                list1 = list1.next
        
        if list1 != None:
            temp.next = list1
        
        if list2 != None:
            temp.next = list2

        return dummy.next
              