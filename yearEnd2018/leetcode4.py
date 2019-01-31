# https://leetcode.com/problems/add-two-numbers/#/description

# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    return_list = None

    def __append_item(self, value):
        if self.return_list == None:
            self.return_list = ListNode(value)
            return

        node_iter = self.return_list
        while not node_iter.next == None:
            node_iter = node_iter.next

        node_iter.next = ListNode(value)

    def __get_length(self,node):
        length = 0
        n = node

        while not n == None:
            n = n.next
            length = length + 1

        return length

    def __pad_list(self, node, count):
        n = node

        while not n.next == None:
            n = n.next

        for i in range(count):
            n.next = ListNode(0)
            n = n.next
        
        return

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l1_length = self.__get_length(l1)
        l2_length = self.__get_length(l2)
        top_item = None
        bottom_item = None
        self.return_list = None

        if l1_length > l2_length:
            top_item = l1
            self.__pad_list(l2, l1_length - l2_length)
            bottom_item = l2
        else:
            top_item = l2
            self.__pad_list(l1,l2_length - l1_length)
            bottom_item = l1

        l1_length = self.__get_length(l1)
        l2_length = self.__get_length(l2)

        item1 = top_item
        item2 = bottom_item
        carry_number = 0

        while not item1 == None:
            new_val = item1.val + item2.val + carry_number

            if new_val >= 10:
                carry_number = 1
                new_val = new_val - 10
            else:
                carry_number = 0

            self.__append_item(new_val)

            # Advance the iterator
            item1 = item1.next
            item2 = item2.next
        
        if carry_number == 1:
            self.__append_item(1)
        
        return self.return_list

n1 = ListNode(2)
n2 = ListNode(7)
n1.next = n2

m1 = ListNode(6)
m2 = ListNode(4)
m3 = ListNode(3)
m1.next = m2
m2.next = m3

s = Solution()
print(s.addTwoNumbers(n1,m1))  # Should give [8,1,4]
