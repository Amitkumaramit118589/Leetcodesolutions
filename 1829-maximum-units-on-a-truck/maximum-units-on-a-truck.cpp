bool cmp(vector<int>v1,vector<int>v2){
    return v1[1]>v2[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& bx, int tsize) {
        sort(bx.begin(),bx.end(),cmp);
        int ans=0;
        for(int i=0;i<bx.size();i++){
            if(bx[i][0]<=tsize) {
                  ans+=bx[i][1]*bx[i][0];
                  tsize-=bx[i][0];
            }
            else{
                 ans+=bx[i][1]*tsize;
                 tsize=0;
                 return ans;
            }
        }
        return ans;
    }
};