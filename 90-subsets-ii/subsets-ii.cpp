class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    void help(int i,vector<int>curr,vector<int>nums){
        if(i==nums.size()){
            if(st.find(curr)==st.end()){ 
            ans.push_back(curr);
            st.insert(curr);
            }
            return;
        }
        curr.push_back(nums[i]);
        help(i+1,curr,nums);
        curr.pop_back();
        help(i+1,curr,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        help(0,{},nums);
        return ans;
    }
};