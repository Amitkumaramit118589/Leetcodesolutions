class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int mid= (st+end)/2;
        if(n==1) return nums[0];
        while(st<=end){
            mid=(st+end)/2;

            if(mid==0 && nums[mid]!=nums[mid+1]) return nums[mid];  //out of bound condition 
            if(mid==n-1 && nums[mid]!=nums[mid-1])return nums[mid];  // out of bound condition

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
           if(mid%2==0){ //even
            if(nums[mid]==nums[mid-1]) end=mid-1;
            else st=mid+1;
           }
            else{   //odd
                if(nums[mid]==nums[mid-1]) st=mid+1;
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};