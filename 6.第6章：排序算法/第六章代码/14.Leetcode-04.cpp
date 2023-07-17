class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> temp(n + m);
        int p1 = 0, p2 = 0, k = 0;
        while (p1 < n || p2 < m) {
            if (p2 == m || (p1 < n && nums1[p1] <= nums2[p2])) {
                temp[k++] = nums1[p1++];
            } else {
                temp[k++] = nums2[p2++];
            }
        }
        double a = temp[(n + m) /2], b = temp[(n + m) /2];
        if ((n + m) % 2 == 0) b = temp[(n + m) /2 - 1];
        return (a + b) / 2.0;
    }
};