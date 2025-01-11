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
    ListNode* middleNode(ListNode* head) {
        int counter = 0;
        ListNode* temp = head;
        while(temp->next != NULL)
        {
            counter++;
            temp = temp->next;
        }
        if(counter % 2 == 0)
            counter =counter / 2;
        else 
            counter = counter / 2 + 1;
        for(int i = 0; i < counter; i++)
        {
            head = head->next;
        }
        return head;
    }
};