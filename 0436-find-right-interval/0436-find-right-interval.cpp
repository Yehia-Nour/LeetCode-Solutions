class Solution {
public:
    int find(vector<vector<int>>& arr, int target) {
        int start = 0, end = arr.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid][0] >= target) {
                ans = arr[mid][2]; 
                end = mid - 1;  
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int endTime = intervals[i][1];
            int originalIndex = intervals[i][2];
            res[originalIndex] = find(intervals, endTime);
        }

        return res;
    }
};
