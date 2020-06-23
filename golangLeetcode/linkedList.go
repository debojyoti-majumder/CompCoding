package main

import (
	"fmt"
)

// MyListNode : Is represntation of a linked list node
type MyListNode struct {
	someData string
	next     *MyListNode
}

func initListNode(data string) *MyListNode {
	return &MyListNode{
		someData: data,
		next:     nil,
	}
}

func printOutAllNodes(myNodeHead *MyListNode) {
	iterator := myNodeHead
	fmt.Print("[ ")

	for iterator != nil {
		fmt.Print(iterator.someData)
		fmt.Print(" ")

		// This is moving forward on the list
		iterator = iterator.next
	}

	fmt.Println("]")
}

func appendToNode(head *MyListNode, newNode *MyListNode) {
	tmp := head.next
	head.next = newNode
	newNode.next = tmp
}

func main() {
	node1 := initListNode("Node 1")
	node2 := initListNode("Node 2")
	node3 := initListNode("Node 3")
	node4 := initListNode("Node 4")

	appendToNode(node1, node2)
	appendToNode(node2, node3)
	appendToNode(node3, node4)

	fmt.Println("I am implementing a linked list in go")
	printOutAllNodes(node1)
}
