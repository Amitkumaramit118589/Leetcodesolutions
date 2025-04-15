class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftprod=INT_MIN;
        int rightprod=INT_MIN;
        int left=1;
        int right=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            left *=nums[i];
            leftprod=max(leftprod,left);
             if(nums[i]==0) left=1;
        }
        for(int i=n-1;i>=0;i--){
             right *=nums[i];
            
            rightprod=max(rightprod,right);

            if(nums[i]==0) right=1;
        }
        return max(leftprod,rightprod);
    }
};