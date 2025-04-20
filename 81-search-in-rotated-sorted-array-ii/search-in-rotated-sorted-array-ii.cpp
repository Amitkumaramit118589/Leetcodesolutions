class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st=0;
        int n=nums.size();
        int end=n-1;
        int mid=(st+end)/2;

        while(st<=end){
            mid=(st+end)/2;
            if(nums[mid]==target){
               return true;
            }
            if(nums[mid]==nums[st] && nums[mid]==nums[end]){
                end=end-1;
                st=st+1;
                continue;
            }
            if(nums[st]<=nums[mid]){
                if(nums[st]<=target && target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[end]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
        
    }
};