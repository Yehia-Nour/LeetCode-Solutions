class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;

        for (int i = 1; i <= n; ++i) {
            que.push(i);
        }

        while (que.size() > 1) {
            for (int i = 0; i < k - 1; ++i) {
                que.push(que.front());
                que.pop();
            }
            que.pop();
        }

        return que.front();
    }
};