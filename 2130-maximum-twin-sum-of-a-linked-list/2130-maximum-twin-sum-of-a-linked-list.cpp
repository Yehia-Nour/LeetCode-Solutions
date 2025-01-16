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
    int pairSum(ListNode* head) {
        vector<ListNode*> vec;
        
        ListNode* current = head;
        while (current) {
            vec.push_back(current);
            current = current->next;
        }

        vector<int> vecNum;
        int j = vec.size() - 1;

        for(int i = 0; i < vec.size() / 2; i++)
        {
            vecNum.push_back(vec[i]->val + vec[j]->val);
            j--;
        }

        auto maxElement = max_element(vecNum.begin(), vecNum.end());
        return *maxElement;
    }
};