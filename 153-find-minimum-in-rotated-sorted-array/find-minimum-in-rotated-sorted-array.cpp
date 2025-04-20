class Solution {
public:
   int findMin(vector<int>& nums) {
    int st = 0, end = nums.size() - 1;

    // Case: array is already sorted
    if (nums[st] <= nums[end]) return nums[st];

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Check if mid is inflection point
        if (mid < end && nums[mid] > nums[mid + 1]) return nums[mid + 1];
        if (mid > st && nums[mid] < nums[mid - 1]) return nums[mid];

        // Decide which side to go
        if (nums[mid] >= nums[st]) {
            // Left part is sorted, move to right
            st = mid + 1;
        } else {
            // Right part is sorted, move to left
            end = mid - 1;
        }
    }

    return -1; // should never be hit if input is valid
}

};