class KthLargest {
public:
    typedef pair<int, int> PII;
    int tot, k;
    set<PII> s;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto x : nums) {
            add(x);
        }
        return ;
    }
    
    int add(int val) {
        if (s.size() < k) {
            s.insert(PII(val, tot++));
        } else {
            if (s.begin()->first < val) {
                s.insert(PII(val, tot++));
            }
        }
        if (s.size() > k) s.erase(s.begin());
        return s.begin()->first;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
