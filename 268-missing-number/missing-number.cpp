class Solution {
public:
    int missingNumber(vector<int>& a) {
        int N=a.size();
        int arraysum=0;
        int totalsum=N*(N+1)/2;
        for(int i=0;i<N;i++){
            arraysum+=a[i];
        }
        return totalsum-arraysum;
    }
};