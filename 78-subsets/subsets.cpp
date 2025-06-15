class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>curr,vector<int>nums,int i){
        if(i>=nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(curr,nums,i+1);
        curr.pop_back();
        solve(curr,nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        int i=0;
        solve(curr,nums,i);
        return ans;
    }
};