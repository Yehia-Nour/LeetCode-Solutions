/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *head_less = nullptr;
        ListNode *curr_less = nullptr;
        ListNode *head_greater = nullptr;
        ListNode *curr_greater = nullptr;

        while(head) {
            if (head->val < x) {
                if (!head_less) {
                    head_less = new ListNode(head->val);
                    curr_less = head_less;
                } else {
                    curr_less->next = new ListNode(head->val);
                    curr_less = curr_less->next;
                }
            } else {
                if (!head_greater) {
                    head_greater = new ListNode(head->val);
                    curr_greater = head_greater;
                } else {
                    curr_greater->next = new ListNode(head->val);
                    curr_greater = curr_greater->next;
                }
            }
            head = head->next;
        }

        if (!head_less) return head_greater;

        curr_less->next = head_greater;
        return head_less;
    }
};