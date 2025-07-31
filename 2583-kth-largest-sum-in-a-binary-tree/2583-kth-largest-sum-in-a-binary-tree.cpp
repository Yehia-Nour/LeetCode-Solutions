class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            minHeap.push(sum);
            if ((int)minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.size() == k ? minHeap.top() : -1;
    }
};
