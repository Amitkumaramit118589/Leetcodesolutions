class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int winodd=0;
        int count=0;
        int result=0;
        while(j<n){
            if(nums[j]%2!=0) winodd++;
            while(i<j &&(nums[i]%2==0 || winodd>k)){
                if(nums[i]%2==0) count++;
                else{
                    winodd-=1;
                    count=0;
                } 
                
                i++;
            }

            if(winodd==k) result+=1+count;
            j++;

        }
        return result;
    }
};