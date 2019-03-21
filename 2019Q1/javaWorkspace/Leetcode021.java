public class Leetcode021 {

    public class ListNode {
        int val;
        ListNode next;
        public ListNode(int x) { val = x; }
    }
 
    class Solution {
        private ListNode mergedList;
        private ListNode iterator;

        private void addToList(int val) {
            if( mergedList != null ) {
                iterator.next = new ListNode(val);
                iterator = iterator.next;
            } else {
                mergedList = new ListNode(val);
                iterator = mergedList;
            }

            iterator.next = null;
        }

        private void addRemaining(ListNode nd) {
            ListNode iterator = nd;

            while( iterator != null ) {
                addToList(iterator.val);
                iterator = iterator.next;
            }
        }

        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            ListNode iterator_1 = l1;
            ListNode iterator_2 = l2;

            while(iterator_1 != null && iterator_2 != null ) {
                if( iterator_1.val < iterator_2.val ) {
                    addToList(iterator_1.val);
                    iterator_1 = iterator_1.next;
                } else {
                    addToList((iterator_2.val));
                    iterator_2 = iterator_2.next;
                }
            }

            addRemaining(iterator_1);
            addRemaining(iterator_2);
            return mergedList;
        }
    }

    public static void DispplayList(ListNode nd) {
        ListNode iterator = nd;

        while( iterator != null ) {
            System.out.print(iterator.val + " ");
            iterator = iterator.next;
        }

        System.out.println();
    }

    public static void main(String args[]) {
    }
}
