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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int sum = 0;

        head = head->next;

        while (head) {
                sum += head->val;
            if (head->val == 0) {
                if (sum > 0) {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                    sum = 0;
                }
            }
            head = head->next;
        }

        return dummy->next;
    }
};