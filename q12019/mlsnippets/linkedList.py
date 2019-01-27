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
            print(it.getData())
            it = it.getNext()

    def findItem(self, data):
        iterator = self.head

        while iterator != None:
            if iterator.data == data:
                return iterator

            iterator = iterator.getNext()

        return None
            


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
