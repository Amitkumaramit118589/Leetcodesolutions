class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='[')st.push('[');
            else{
                if(st.size()>0){
                    st.pop();
                }
            }
        }
        return (st.size()+1)/2;
    }
};