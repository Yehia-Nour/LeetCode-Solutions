class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;

        while (cur) {
            len++;
            cur = cur->next;
        }

        int n = len / k;
        int m = len % k;

        vector<ListNode*> vec(k, nullptr);
        cur = head;

        for (int i = 0; i < k; ++i) {
            ListNode* partHead = cur;
            int partSize = n + (m > 0 ? 1 : 0);

            for (int j = 0; j < partSize - 1 && cur; ++j) {
                cur = cur->next;
            }

            if (cur) {
                ListNode* next = cur->next;
                cur->next = nullptr;
                cur = next;
            }

            vec[i] = partHead;
            if (m > 0) m--; 
        }

        return vec;
    }
};
