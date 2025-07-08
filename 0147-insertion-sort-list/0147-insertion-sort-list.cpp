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
        ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = head;
        while(current){
            ListNode* prev = dummy;
            ListNode* nextNode = current->next;
            while(prev->next && prev->next->val < current->val){
                prev = prev->next;
            }
            current->next = prev->next;
            prev->next = current;
            current = nextNode;
        }
        return dummy->next;
    }
};