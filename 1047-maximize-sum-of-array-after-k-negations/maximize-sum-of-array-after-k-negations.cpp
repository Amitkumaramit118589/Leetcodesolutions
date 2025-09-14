class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        int t;
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        while(k-- && pq.size()>0){
            t=(pq.top());
            if(t==0)break;
            sum-=t;
            pq.pop();
            pq.push(-t);
            sum+=(-t);
        }
        
        return sum;

    }
};