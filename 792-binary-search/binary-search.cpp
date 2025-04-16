class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int mid=n/2;
        int low=0;
        int high=n-1;
        while(low<=high){
            if(nums[mid]>target){
              // low=0;
               high=mid-1;
               mid=(low+high)/2;
            }
            else if(nums[mid]<target){
                low=mid+1;
               // high=n-1;
                mid=(low+high)/2;
            }
            else return mid;
        }
        return -1;
    }
};