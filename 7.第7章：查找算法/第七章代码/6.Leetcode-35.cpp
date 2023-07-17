class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0, tail = nums.size(), mid;
        while (head < tail) {
            mid = (head + tail) / 2;
            if (nums[mid] < target) head = mid + 1;
            else tail = mid;
        }
        return head;
    }
};