class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int mid=(st+end)/2;
        int leftmost=-1;
        while(st<=end){
            mid=(st+end)/2;
            if(nums[mid]==target){
               leftmost=mid; 
               end=mid-1;
            } 
            else if(nums[mid]>target){
                end= mid-1;
            }
            else{
                st=mid+1;
            }
        }
        int rightmost=-1;
        st=0;
        end=n-1;
        while(st<=end){
            mid=(st+end)/2;
            if(nums[mid]==target){
                st=mid+1;
                rightmost=mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return {leftmost,rightmost};
    }
};