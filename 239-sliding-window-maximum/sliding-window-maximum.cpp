class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nextGreater(n);
        stack<int> st;

        // Compute next greater element indices
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int j = 0;
        vector<int> res(n - k + 1);

        for (int i = 0; i <= n - k; i++) {
            if (j < i) j = i;
            while (nextGreater[j] < i + k) {
                j = nextGreater[j];
            }
            res[i] = nums[j];
        }

        return res;
    }
};
