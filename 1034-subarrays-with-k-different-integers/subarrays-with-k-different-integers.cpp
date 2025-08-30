class Solution {
public:
    int subarraywithk(vector<int> &nums,int k){
        int n=nums.size();
        map<int,int>mp;
        int i=0,j=0;
        int res=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
               mp[nums[i]]--;
               if(mp[nums[i]]==0)mp.erase(nums[i]);
               i++;
            }
            res+=j-i+1;
            j++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int k_tak=subarraywithk(nums,k);
        int k_1tak=subarraywithk(nums,k-1);
        return k_tak-k_1tak;
    }
};