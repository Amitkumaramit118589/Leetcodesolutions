class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            
            int aestroid = asteroids[i];

            while(!st.empty() && aestroid < 0 && st.top() > 0) {

                if(abs(aestroid) == st.top()) {
                    aestroid = 0;
                    st.pop();
                    break;
                }

                if(abs(aestroid) > st.top()) {
                    st.pop();
                    continue;
                }

                if(abs(aestroid) < st.top()) {
                    aestroid = 0;
                    break;
                }

            }

            if(aestroid !=0){
                st.push(aestroid);
            }
        }

        vector<int> res;

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};