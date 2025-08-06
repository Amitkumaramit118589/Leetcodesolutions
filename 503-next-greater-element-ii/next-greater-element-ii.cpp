class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;
        vector<int>ans(n);
        
        for(int i = n-2; i >= 0 ; i--){
            s.push(nums[i]);
        }
        // next greater element
        for(int i = n-1; i >=0 ; i--){
            while(!s.empty() && s.top() <= nums[i]) s.pop();

            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();

            s.push(nums[i]);
        }
        return ans;
    }
};   