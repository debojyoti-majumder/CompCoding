# Simple Linked list implmentation to understand python
class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None

    def setNext(self, nextNode):
        self.next = nextNode

    def getData(self):
        return self.data
    
    def getNext(self):
        return self.next

class LinkedList:
    def __init__(self, head = None):
        self.head = Node(head)

    def addData(self, data):
        if self.head != None:
            iterator = self.head

            # Navigate to the last node
            while iterator.getNext() != None :
                iterator = iterator.getNext()
            
            iterator.next = Node(data)
        else:
            self.head = Node(data)

    def printAll(self):
        it = self.head

        while it != None:
            print(it.getData(), end=" ")
            it = it.getNext()
        
        # Just a new line feed
        print()

    def findItem(self, data):
        iterator = self.head

        while iterator != None:
            if iterator.data == data:
                return iterator

            iterator = iterator.getNext()

        return None

    def deleteData(self, data):
        # If the node is the first node
        if self.head.data == data:
            self.head = self.head.getNext()
        elif self.head.getNext() != None:
            iterator = self.head
            nextNode = iterator.getNext()

            while nextNode != None:
                # Node found, link needs destoying
                if nextNode.getData() == data:
                    iterator.setNext(nextNode.getNext())

                # Both reference it updated
                iterator = iterator.getNext()
                nextNode = nextNode.getNext()
            


print("Testing out linked list")
myList = LinkedList(40)

# Adding some dummy data
myList.addData(23)
myList.addData(45)
myList.addData(34)

# Simple iteration
myList.printAll()

# Finding element in the list
print(myList.findItem(45))
print(myList.findItem(15))

# Removing element from the list
myList.deleteData(23)
myList.deleteData(34)
myList.printAll()

# Removing the first node
print("After head removed")
myList.deleteData(40)
myList.printAll()

print("With bad data and head removed, list should be empty")
myList.deleteData(30)
myList.deleteData(45)
myList.printAll()

print("Again adding some data")
myList.addData(10)
myList.addData(20)
myList.printAll()