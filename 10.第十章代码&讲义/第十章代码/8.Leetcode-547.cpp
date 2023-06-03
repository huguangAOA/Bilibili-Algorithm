class UnionSet {
public :
    UnionSet(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
    vector<int> fa;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionSet u(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) u.merge(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (u.get(i) == i) ans += 1;
        }
        return ans;
    }
};