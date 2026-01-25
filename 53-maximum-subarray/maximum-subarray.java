class Solution {
    public int maxSubArray(int[] nums) {
        int csum=0;
        int maxsum=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            csum+=nums[i];
            maxsum=Math.max(csum,maxsum);
            if(csum<0) csum=0;
        }
        return maxsum;
    }
}