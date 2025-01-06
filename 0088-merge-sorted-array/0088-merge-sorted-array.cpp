class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec;
        int i = 0;
        while(i < nums1.size())
        {
            if(i < m ) vec.push_back(nums1[i]);
            if(i < n ) vec.push_back(nums2[i]);
            i++;
        }
        for(int i = 0; i < vec.size(); i++)
        {
            nums1[i] = vec[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};