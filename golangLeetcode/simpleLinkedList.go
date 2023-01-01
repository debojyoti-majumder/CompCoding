package main

import "fmt"

type SingleLinkedNode struct {
	Value int
	Next  *SingleLinkedNode
}

type SingleLinkedList struct {
	listHead *SingleLinkedNode
	listTail *SingleLinkedNode
}

func NewSingleLinkedList() *SingleLinkedList {
	newList := new(SingleLinkedList)

	newList.listHead = nil
	newList.listTail = nil

	return newList
}

func (linkedList *SingleLinkedList) AddNode(value int) {
	newNode := new(SingleLinkedNode)

	newNode.Value = value
	newNode.Next = nil

	if linkedList.listTail != nil {
		linkedList.listTail.Next = newNode
		linkedList.listTail = newNode
	} else {
		linkedList.listHead = newNode
		linkedList.listTail = newNode
	}
}

func (linkedList SingleLinkedList) String() string {
	formattedOutput := "[ "

	nodeIterator := linkedList.listHead

	for nodeIterator != nil {
		stringRep := fmt.Sprintf("%d ", nodeIterator.Value)
		nodeIterator = nodeIterator.Next

		formattedOutput += stringRep
	}

	formattedOutput += "]"
	return formattedOutput
}

func main() {
	fmt.Println("Simple Linked list implementation")

	firstList := NewSingleLinkedList()

	firstList.AddNode(20)
	firstList.AddNode(30)
	firstList.AddNode(50)

	fmt.Println(firstList.String())

	// This is where we are using the stringyfier interface
	fmt.Println(firstList)
}
