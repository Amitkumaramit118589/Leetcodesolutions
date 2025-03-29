class Solution {
public:
    void sortColors(vector<int>& nums) {
        int noz=0;
        int noo=0;
        int notw=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) noz++;
            if(nums[i]==1) noo++;
            else{
                notw++;
            }
        } 
        int m=0;
        for(int i=0;i<noz;i++){
            nums[m]=0;
            m++;
        }
        for(int j=noz;j<noz+noo;j++){
            nums[m]=1;
            m++;
        }
        for(int k=noz+noo;k<nums.size();k++){
            nums[m]=2;
            m++;
        }

    }
};