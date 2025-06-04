class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int min_diff = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            min_diff = min(arr[i] - arr[i - 1], min_diff);
        }

        vector<vector<int>> res;

        for (int i = 1; i < arr.size(); ++i) {
            if (min_diff == arr[i] - arr[i - 1]) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};