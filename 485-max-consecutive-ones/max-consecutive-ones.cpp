class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cons=0; //consecutive
        int maxcons=0; //maximum consecutive
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cons++;
            }
            else{
                cons=0;
            }
            maxcons=max(maxcons,cons);
        }
        return maxcons;
    }
};