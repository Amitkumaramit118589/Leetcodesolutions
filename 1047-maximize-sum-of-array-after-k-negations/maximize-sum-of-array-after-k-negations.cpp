class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        int t;
        while(k-- && pq.size()>0){
            t=-(pq.top());
            pq.pop();
            pq.push(t);
        }
        int ans=0;
        while(pq.size()>0){
            ans+=pq.top();
            pq.pop();
        }
        return ans;

    }
};