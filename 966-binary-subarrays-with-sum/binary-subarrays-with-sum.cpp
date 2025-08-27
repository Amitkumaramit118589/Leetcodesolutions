class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int i=0;
        int j=0;
        int winsum=0;
        int result=0;
        int zerosum=0;
        while(j<n){
            winsum+=nums[j];
            while(i<j &&(nums[i]==0 || winsum>goal)){
                if(nums[i]==0)zerosum++;
                else zerosum=0;
                winsum-=nums[i];
                i++;
            }
            if(winsum==goal) result+=1+zerosum;
            j++;
        }
        return result;
    }
};