// Problem URL: https://leetcode.com/problems/odd-even-linked-list/
// Problem ID: 328
// Please add the "ListNode" definition in the package

package com.debojyoti;

import org.hamcrest.CoreMatchers;
import org.junit.Test;
import static org.junit.Assert.assertThat;

public class OddEvenMaker {
    private int oddCounter;
    private int length;

    private ListNode getLastNode(ListNode nd) {
        ListNode it = nd;
        int counter = 1;

        while ( it.next != null ) {
            it = it.next;

            if( counter % 2 != 0 ) oddCounter++;
            counter++;
        }

        length = counter;
        return it;
    }

    public ListNode oddEvenList(ListNode head) {
        if( head == null ) return null;

        // Initializing the list iterator
        ListNode iterator = head;
        ListNode lastNode = getLastNode(head);

        if( this.length < 3 ) return head;

        for ( int i=0; i<oddCounter; i++ ) {
            ListNode oddNode = iterator;
            ListNode evenNode = iterator.next;

            // The node should be odd one
            oddNode.next = evenNode.next;

            // Updating the last node
            evenNode.next = null;
            lastNode.next = evenNode;
            lastNode = evenNode;

            iterator = oddNode.next;
        }

        return head;
    }

    @Test
    public void doTest1() {
        ListNode nd5 = new ListNode(5);
        ListNode nd4 = new ListNode(4, nd5);
        ListNode nd3 = new ListNode(3, nd4);
        ListNode nd2 = new ListNode(2, nd3);
        ListNode nd1 = new ListNode(1, nd2);

        ListNode retVal = oddEvenList(nd1);
        String r = retVal.buildString();
        assertThat(r, CoreMatchers.equalTo("[ 1 3 5 2 4 ]"));
    }

    @Test
    public void smallerTest() {
        ListNode nd3 = new ListNode(3);
        ListNode nd2 = new ListNode(2, nd3);
        ListNode nd1 = new ListNode(1, nd2);

        ListNode retVal = oddEvenList(nd1);
        String r = retVal.buildString();
        assertThat(r, CoreMatchers.equalTo("[ 1 3 2 ]"));
    }
}
