class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n=nums.size();
      int st=0;
      int end=n-1;
      int mid=(st+end)/2;
      while(st<=end){
        mid=(st+end)/2;
        if(nums[mid]==target)return mid;
        if(nums[mid]>=nums[st]){
            if(nums[st]<=target && target<=nums[mid]) end=mid-1;
            else{
                st=mid+1;
            }
        }
        else{
            if(nums[mid]<=target && target<=nums[end]) st=mid+1;
            else{
                end=mid-1;
            }
        }
      }
      return -1;
 
    }
};