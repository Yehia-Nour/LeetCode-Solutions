/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode DeleteMiddle(ListNode head) {
        if (head.next == null)
            return null;

        int count = 0;
        ListNode temp = head;
        while (temp != null)
        {
            count++;
            temp = temp.next;
        }

        int mid = count / 2 - 1;
        
        temp = head;
        for (int i = 0; i < mid; i++)
            temp = temp.next;

        temp.next = temp.next.next;

        return head;
    }
}