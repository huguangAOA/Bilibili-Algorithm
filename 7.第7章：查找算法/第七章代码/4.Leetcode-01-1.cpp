class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        vector<int> ret(2);
        for (int i = 0, I = nums.size(); i < I; i++) {
            if (h.find(target - nums[i]) != h.end()) {
                ret[0] = h[target - nums[i]];
                ret[1] = i;
                break;
            }
            h[nums[i]] = i;
        }
        return ret;
    }
};