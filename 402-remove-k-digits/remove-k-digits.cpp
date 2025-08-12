class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<num.size();i++){

            while(!st.empty() && num[i]<st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
         while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        if(st.empty()) return{"0"};
       
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        //leading zero hatana
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);
        if (ans.empty()) return "0";

        return ans;
    }
};