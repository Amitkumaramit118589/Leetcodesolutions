class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);

        int n = a.size(), m = b.size();
        int lo = 0, hi = n;
        int total = n + m;

        while (lo <= hi) {
            int aLeft = (lo + hi) / 2;
            int bLeft = (total + 1) / 2 - aLeft;

            int aLeftMax = (aLeft == 0) ? INT_MIN : a[aLeft - 1];
            int aRightMin = (aLeft == n) ? INT_MAX : a[aLeft];

            int bLeftMax = (bLeft == 0) ? INT_MIN : b[bLeft - 1];
            int bRightMin = (bLeft == m) ? INT_MAX : b[bLeft];

            if (aLeftMax <= bRightMin && bLeftMax <= aRightMin) {
                if (total % 2 == 0) {
                    return (max(aLeftMax, bLeftMax) + min(aRightMin, bRightMin)) / 2.0;
                } else {
                    return max(aLeftMax, bLeftMax);
                }
            } else if (aLeftMax > bRightMin) {
                hi = aLeft - 1;
            } else {
                lo = aLeft + 1;
            }
        }

        return -1; // Should never be reached for valid inputs
    }
};
