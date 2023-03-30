class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        long long ans = 0, flag = 0;
        while (n--) {
            ans = *s.begin();
            s.erase(s.begin());
            if (ans % 5 == 0) flag = 2;
            else if (ans % 3 == 0) flag = 1;
            else flag = 0;
            switch (flag) {
                case 0: s.insert(ans * 2);
                case 1: s.insert(ans * 3);
                case 2: s.insert(ans * 5);
            }
        }
        return ans;
    }
};
