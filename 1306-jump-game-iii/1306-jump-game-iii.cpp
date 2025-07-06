class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        for (int level = 0, size = 1; !q.empty(); level++, size = q.size()) {
            while (size--) {
                int cur = q.front();
                if (arr[cur] == 0) return true;
                q.pop();

                int right = cur + arr[cur];
                if (right < n && !visited[right]) {
                    q.push(right);
                    visited[right] = true;
                } 
                

                int left = cur - arr[cur];
                if (left >= 0 && !visited[left]) {
                    q.push(left);
                    visited[left] = true;
                }
            }
        }
        return false;
    }
};