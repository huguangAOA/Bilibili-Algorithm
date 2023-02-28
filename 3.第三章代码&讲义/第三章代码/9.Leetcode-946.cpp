class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int x = 0, n = pushed.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty() || s.top() != popped[i]) {
                while (x < pushed.size() && pushed[x] != popped[i]) {
                    s.push(pushed[x]);
                    x += 1;
                }
                if (x == pushed.size()) return false;
                s.push(pushed[x]); x += 1;
            }
            s.pop();
        }
        return true;
    }
};