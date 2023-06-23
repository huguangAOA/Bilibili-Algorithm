class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (limit < 0) return 0;
        deque<int> min_q, max_q;
        int l = 0, ans = 1;
        min_q.push_back(0);
        max_q.push_back(0);
        for (int r = 1, n = nums.size(); r < n; r++) {
            while (!min_q.empty() && nums[r] < nums[min_q.back()]) min_q.pop_back();
            while (!max_q.empty() && nums[r] > nums[max_q.back()]) max_q.pop_back();
            min_q.push_back(r);
            max_q.push_back(r);
            while (nums[max_q.front()] - nums[min_q.front()] > limit) {
                if (min_q.front() == l) min_q.pop_front();
                if (max_q.front() == l) max_q.pop_front();
                l += 1;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};