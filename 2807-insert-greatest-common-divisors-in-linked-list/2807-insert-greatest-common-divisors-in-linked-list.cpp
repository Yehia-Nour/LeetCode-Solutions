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
    int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *cur = head;
        ListNode *next = head->next;

        while (next) {
            ListNode *newNode = new ListNode(GCD(cur->val, next->val));
            cur->next = newNode;
            newNode->next = next;
            cur = next;
            next = next->next;
        }

        return head;
    }
};