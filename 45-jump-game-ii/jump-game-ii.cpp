
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int jumps = 0;
        int currentReach = 0;
        int farthestReach = 0;

        // iterate up to second-last element
        for (int i = 0; i < n - 1; i++) {
            // update farthest point reachable from current index
            farthestReach = max(farthestReach, i + nums[i]);

            // if we reached the boundary of the current jump
            if (i == currentReach) {
                jumps++;
                currentReach = farthestReach;

                // optimization: if already can reach or pass last index
                if (currentReach >= n - 1) break;
            }
        }

        return jumps;
    }
};
