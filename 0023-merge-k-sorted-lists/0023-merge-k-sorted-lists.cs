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
    ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode op = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                op.next = list1;
                list1 = list1.next;
            } else {
                op.next = list2;
                list2 = list2.next;
            }
            op = op.next;
        }

        op.next = (list1 != null) ? list1 : list2;
        return dummy.next;
    }

    public ListNode MergeKLists(ListNode[] lists) {
        if (lists == null || lists.Length == 0) return null;

        ListNode merged = lists[0];

        for (int i = 1; i < lists.Length; i++) {
            merged = MergeTwoLists(merged, lists[i]);
        }

        return merged;
    }
}
