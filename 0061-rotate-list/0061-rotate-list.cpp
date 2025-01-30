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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* curr = head;
        int length = 1;
        while (curr->next)
        {
            ++length;
            curr = curr->next;
        }
		k %= length;

        ListNode *prev = head;
        for (int i = 0; i < length - k - 1; ++i)
        {
            prev = prev->next;
        }

        curr-> next = head;
        head = prev->next;
        prev->next = nullptr;

        return head;
    }
};