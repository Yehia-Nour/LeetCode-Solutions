/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        int lengthA = 0;
        ListNode *currA = headA;
        while(currA->next)
        {
            currA = currA->next;
            ++lengthA;
        }
        int lengthB = 0;
        ListNode *currB = headB;
        while(currB->next)
        {
            currB = currB->next;
            ++lengthB;
        }

        if (currA != currB) return nullptr;

        currA = headA;
        currB = headB;
        int n = lengthA - lengthB;
        if (n < 0)
        {
            for (int i = 0; i < n * -1; ++i) currB = currB->next;
        }
        else 
        {
            for (int i = 0; i < n; ++i) currA = currA->next;
        }
        while (currA != currB)
        {
            currA = currA->next;
            currB = currB->next;
        }
        return currA;
    }
};