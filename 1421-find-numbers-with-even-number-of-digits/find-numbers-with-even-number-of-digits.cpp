class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evencnt=0;
        for(int i=0;i<nums.size();i++){
            int t=nums[i];
            int ncnt=0;
            while(1){
                int d=t/10;
               if(d>0){
                ncnt++;
                t=d;
               }
               else{
                ncnt++;
                break;
               } 
            }
           if(ncnt%2==0) evencnt++;
        }
        return evencnt;
    }
};