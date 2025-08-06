class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int j=0;
            while(j<nums2.size()){
                if(nums2[j]==nums1[i]){
                    break;
                }
                j++;
            }
            int k=j+1;
            while(k<nums2.size()){
                if(nums2[k]>nums1[i]){
                    ans.push_back(nums2[k]);
                    break;
                }
                k++;
            }
            if(k==nums2.size())ans.push_back(-1);

        }
        return ans;
    }
};