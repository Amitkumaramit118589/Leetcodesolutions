class Solution {
public:
    int help(vector<int>& nums ,int st, int end, int tar) {
    if(st > end) return -1;

    int mid = (st + end) / 2;
    if(nums[mid] == tar) return mid;

    if(tar < nums[mid]) {
        return help(nums, st, mid - 1, tar);
    } else {
        return help(nums, mid + 1, end, tar);
    }
}

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    return help(nums, low, high, target);
}

};