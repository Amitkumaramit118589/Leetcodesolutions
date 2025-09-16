class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int i=0;
        int j=p.size()-1;
        int boat=0;
        while(i<=j){
            if(i==j){
                boat++;
                i++;
            }
            else if(p[i]+p[j]<=limit){
                boat++;
                i++;
                j--;
            } 
            else{
                boat++;
                j--;
            }
        }
      return boat;
    }
};