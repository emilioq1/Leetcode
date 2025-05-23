from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#   def __init__(self, val=0, next=None);
#       self.val = val
#       self.next = next
class ListNode:
    def __init__(self, value, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        curr = head
        
        carry = 0

        while l1 != None or l2 != None or carry != 0:
            x = (l1.val) if l1 != None else 0
            y = (l2.val) if l2 != None else 0
            sum = carry + x + y
            carry = sum // 10

            curr.next = ListNode(val=sum % 10)
            curr = curr.next
            
            l1 = l1.next if l1 != None else None
            l2 = l2.next if l2 != None else None

        return head.next
