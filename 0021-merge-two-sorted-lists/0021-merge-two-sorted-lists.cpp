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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode *curr1;
        ListNode *prev;
        ListNode *curr2;

        while(list1)
        {
            curr1 = list1;
            list1 = list1->next;
            curr2 = list2->next;
            prev = list2;
            while(true)
            {
                if(curr1->val <= list2->val)
                {
                    curr1->next = list2;
                    list2 = curr1;
                    break;
                }
                else if(curr2 == nullptr)
                {
                    curr1->next = nullptr;
                    prev->next = curr1;
                    break;
                }
                else if(curr1->val <= curr2->val)
                {
                    curr1->next = curr2;
                    prev->next = curr1;
                    break;
                }
                else
                {
                    curr2 = curr2->next;
                    prev = prev->next;
                }
            }
        }
        return list2;
    }
};