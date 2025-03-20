class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push(nums[i]);
        }

        int alice, bob;
        vector<int> vecResult;

        for (int i = 0; i < nums.size() / 2; ++i) {
            alice = minHeap.top();
            minHeap.pop();
            bob = minHeap.top();
            minHeap.pop();

            vecResult.push_back(bob);
            vecResult.push_back(alice);
        }

        return vecResult;
    }
};