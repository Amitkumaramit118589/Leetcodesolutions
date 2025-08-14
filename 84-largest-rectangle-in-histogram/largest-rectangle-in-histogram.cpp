class Solution {
public:
    vector<int> nse(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        // Last element ka NSE hamesha n hota hai (right me koi nahi)
        ans[n - 1] = n;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) { // >= taaki equal heights bhi pop ho
                st.pop();
            }
            if (st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int> arr) { // previous smaller element
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        // First element ka PSE hamesha -1 hota hai (left me koi nahi)
        ans[0] = -1;
        st.push(0);

        for (int i = 1; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) { // >= taaki equal heights bhi pop ho
                st.pop();
            }
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nseidx = nse(heights);
        vector<int> pseidx = pse(heights);
        int n = nseidx.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int area = (nseidx[i] - 1 - pseidx[i]) * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};
