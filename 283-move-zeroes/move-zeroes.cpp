class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int k = 0;  // Position to place the next non-zero element

    // Move non-zero elements forward
    for (int j = 0; j < n; j++) {
        if (nums[j] != 0) {
            swap(nums[k], nums[j]);
            k++;
        }
    }
}
};