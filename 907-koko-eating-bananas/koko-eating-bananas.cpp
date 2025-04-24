class Solution {
public:
    long long help(vector<int> &v, int hourly) {
        long long totalH = 0;
        for (int i = 0; i < v.size(); i++) {
            totalH += (v[i] + hourly - 1) / hourly; // ceiling without using ceil()
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxm = *max_element(piles.begin(), piles.end());
        int st = 1, end = maxm;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (help(piles, mid) > (long long)h) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return st;
    }
};
