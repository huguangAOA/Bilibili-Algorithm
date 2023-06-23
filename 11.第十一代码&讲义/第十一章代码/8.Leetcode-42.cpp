class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        for (int i = 0, n = height.size(); i < n; i++) {
            while (!s.empty() && height[s.top()] < height[i]) {
                int h6 = height[s.top()];
                s.pop();
                if (s.empty()) break;
                ans += (min(height[s.top()], height[i]) - h6) * (i - s.top() - 1);
            }
            s.push(i);
        }
        return ans;
    }
};