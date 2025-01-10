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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* prev = head;
        ListNode* next = head->next;

        while(prev->next != NULL)
        {
            if(next->val == val)
            {
                prev->next = next->next;
                delete next;
                next = prev->next;
            }
            else
            {
                prev = prev->next;
                next = next->next;
            }
        }
        if(head->val == val) head = head->next;
        return head;


    }
};