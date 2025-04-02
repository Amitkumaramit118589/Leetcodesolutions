class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        vector<int>v1;
        vector<int>v2;
        
        
        for(int i=0;i<n;i++){
            if(arr[i]>=0) v1.push_back(arr[i]);
            else v2.push_back(arr[i]);
        }
        
        for(int j=0;j<n/2;j++){
            arr[2*j]=v1[j];
            arr[2*j+1]=v2[j];
        }
        return arr;
    }
};