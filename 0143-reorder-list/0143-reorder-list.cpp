class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        vector<ListNode*> vec;
        
        ListNode* current = head;
        while (current) {
            vec.push_back(current);
            current = current->next;
        }

        int i = 0;
        int j = vec.size() - 1;

        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) break;
            vec[j]->next = vec[i];
            j--;
        }

        vec[i]->next = nullptr;
    }
};
