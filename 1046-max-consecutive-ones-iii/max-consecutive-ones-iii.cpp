class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //int cnt=0;
        int i=0;
        int j=0;
        int c=0;
        int ans=0;
        while(i<nums.size()){
            if(nums[i]==0)c++;
            while(c>k){
              if(nums[j]==0)c--;
               j++;
            }
          ans= max(ans,i-j+1);
          i++;
           // cnt=0;
        

        }
        return ans;
    }
};