class Solution {
public:
    void pushStack(string &s, stack<char> &s1) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == '#') { 
                if (!s1.empty()) s1.pop();
            } else s1.push(s[i]);
        }
        return ;
    }
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        pushStack(s, s1);
        pushStack(t, s2);
        if (s1.size() != s2.size()) return false;
        while (!s1.empty()) {
            if (s1.top() != s2.top()) return false;
            s1.pop(), s2.pop();
        }
        return true;
    }
};