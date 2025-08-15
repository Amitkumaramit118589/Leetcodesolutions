class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1)return nums;
        stack<int>st;
        st.push(n-1);
        vector<int>ngi(n);
        ngi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(st.empty()) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);
        }
        
        //next greater ke hisab se window me check karna aur jump karna
        vector<int> ans;
        int j=0;
        for(int i=0;i<=n-k;i++){
            if (j < i) j = i;
            while(j<n && ngi[j]<i+k){
                j=ngi[j];
            }
            ans.push_back(nums[j]);
        }
        return ans;
    }
};