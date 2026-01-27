class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int n=nums.length;
        
       for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum==0){
                ans.add(Arrays.asList(nums[i], nums[j], nums[k]));
                j++;
                k--;
                // duplicate j skip
                 while(j < k && nums[j] == nums[j - 1]) j++;
                 // duplicate k skip
                 while(j < k && nums[k] == nums[k + 1]) k--;
                }
                else{
                    k--;
                }
            }
       }
        return ans;
    }
}