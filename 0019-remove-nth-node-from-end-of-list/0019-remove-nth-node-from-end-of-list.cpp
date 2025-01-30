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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;

        ListNode* curr = head;
        int length = 0;
        while (curr)
        {
            ++length;
            curr = curr->next;
        }
        int size = length - n;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        curr = head;
        for (int i = 0; i < size; ++i)
        {
            curr = curr->next;
            prev = prev->next;
        }

        prev->next = curr->next;
        delete curr;
        return dummy->next;

    }
};