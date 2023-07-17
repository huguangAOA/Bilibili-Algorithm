class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j) -> bool {
            if (nums[i] != nums[j]) return nums[i] < nums[j];
            return i < j;
        });
        for (int i = 0, I = n - 1; i < I; i++) {
            if (nums[ind[i]] - nums[ind[i + 1]]) continue;
            if (ind[i + 1] - ind[i] <= k) return true;
        }
        return false;
    }
};