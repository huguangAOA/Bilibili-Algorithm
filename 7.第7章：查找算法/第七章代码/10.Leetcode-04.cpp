#include <cinttypes>
class Solution {
public:
    int findK(vector<int> &n1, int ind1, vector<int> &n2, int ind2, int k) {
        int n = n1.size(), m = n2.size();
        if (k == 1) {
            int a = (n1.size() == ind1 ? INT32_MAX : n1[ind1]);
            int b = (n2.size() == ind2 ? INT32_MAX : n2[ind2]);
            return min(a, b);
        }
        if (n == ind1) return n2[k - 1];
        if (m == ind2) return n1[k - 1];
        int cnt1 = min(k / 2, n - ind1);
        int cnt2 = min(k - cnt1, m - ind2);
        cnt1 = k - cnt2;
        if (n1[ind1 + cnt1 - 1] <= n2[ind2 + cnt2 - 1]) {
            return findK(n1, ind1 + cnt1, n2, ind2, k - cnt1);
        }
        return findK(n1, ind1, n2, ind2 + cnt2, k - cnt2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if ((n + m) % 2 == 1) return findK(nums1, 0, nums2, 0, (n + m) / 2 + 1);
        double a = findK(nums1, 0, nums2, 0, (n + m) / 2);
        double b = findK(nums1, 0, nums2, 0, (n + m) / 2 + 1);
        return (a + b) / 2.0;
    }
};