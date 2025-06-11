class Solution {
public:
    int findClosest(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;
        int closest = arr[0];

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (abs(arr[mid] - target) < abs(closest - target)) {
                closest = arr[mid];
            } else if (abs(arr[mid] - target) == abs(closest - target)) {
                closest = min(closest, arr[mid]);
            }

            if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return closest;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int ans = 0;
        for (int i = 0; i < houses.size(); i++) {
            int temp = findClosest(heaters, houses[i]);
            int d = abs(temp - houses[i]);
            if (ans < d) ans = d;
        }

        return ans;
    }
};