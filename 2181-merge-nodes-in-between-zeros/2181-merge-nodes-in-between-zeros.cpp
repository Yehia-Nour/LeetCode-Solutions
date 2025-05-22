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
        ListNode *dummy = new ListNode(0);
        ListNode *nextZero = head->next;
        ListNode *cur = dummy;

        int sum = 0;
        while(nextZero) {
            sum += nextZero->val;
            if (nextZero->val == 0) {
                if (sum != 0) {
                    ListNode *newNode = new ListNode(sum);
                    cur->next = newNode;
                    cur = newNode;
                    sum = 0;
                }
            }
            nextZero = nextZero->next;
        }

        return dummy->next;
    }
};