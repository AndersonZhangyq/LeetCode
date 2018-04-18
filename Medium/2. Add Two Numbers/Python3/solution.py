class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        head = ListNode(0)
        cur = head
        carry = 0
        while (l1 != None) or (l2 != None):
            a = 0 if l1 == None else l1.val
            b = 0 if l2 == None else l2.val
            sum = a + b + carry
            carry = int(sum / 10)
            cur.next = ListNode(sum % 10)
            cur = cur.next
            l1 = None if l1 == None else l1.next
            l2 = None if l2 == None else l2.next
        if carry != 0:
            cur.next = ListNode(carry)
        return head.next


num_1 = input("First number:\n")
num_1 = [int(x) for x in num_1.split(' ')]
l1 = None
move_1 = None
for i in range(len(num_1)):
    if l1 == None:
        l1 = ListNode(num_1[i])
        move_1 = l1
    else:
        move_1.next = ListNode(num_1[i])
        move_1 = move_1.next

num_2 = input("Second number:\n")
num_2 = [int(x) for x in num_2.split(' ')]
l2 = None
move_2 = None
for i in range(len(num_2)):
    if l2 == None:
        l2 = ListNode(num_2[i])
        move_2 = l2
    else:
        move_2.next = ListNode(num_2[i])
        move_2 = move_2.next

ans = Solution().addTwoNumbers(l1, l2)
stack = list()
while ans != None:
    stack.append(ans.val)
    ans = ans.next
for i in range(len(stack)):
    print(stack.pop(), end="")
