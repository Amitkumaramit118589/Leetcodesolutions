bool cmp(vector<int>&a,vector<int>&b){
         return a[0]<b[0];
}
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        int mini=intervals[0][0];
        int maxi=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=maxi) maxi = max(maxi, intervals[i][1]);
            else{
                ans.push_back({mini,maxi});
                mini=intervals[i][0];
                maxi=intervals[i][1];
            }
        }
        ans.push_back({mini,maxi});
        return ans;
        
    }
};