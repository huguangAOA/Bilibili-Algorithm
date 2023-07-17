class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> h;
        for (auto x : nums) {
            if (h.find(x) != h.end()) return true;
            h.insert(x);
        }
        return false;
    }
};