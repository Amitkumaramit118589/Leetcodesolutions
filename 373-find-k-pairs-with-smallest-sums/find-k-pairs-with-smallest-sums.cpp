class cmp{
    public:
      bool operator()(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
         return a.first>b.first;
      }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq;
       for(int i=0;i<nums1.size();i++){
         pq.push({nums1[i]+nums2[0],{i,0}});
       }
        
        vector<vector<int>>ans;
        pair<int,pair<int,int>>curr;
        while(k-- && pq.size()>0){
            curr=pq.top();
            pq.pop();
            int sum=curr.first;
            int num1idx=curr.second.first;
            int num2idx=curr.second.second;
            ans.push_back({nums1[num1idx],nums2[num2idx]});
            if(num2idx+1<nums2.size()){
                pq.push({nums1[num1idx]+nums2[num2idx+1] , {num1idx,num2idx+1}});
            }

        }
        return ans;
        
    }
};