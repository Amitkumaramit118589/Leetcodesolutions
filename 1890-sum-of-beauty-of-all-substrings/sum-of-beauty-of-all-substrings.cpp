class Solution {
public:
    int countfreq(string s){
         vector<int> freq(26, 0);
            for(int j = 0; j < s.size(); j++) {
                freq[s[j] - 'a']++;
            }
                int minFreq = INT_MAX, maxFreq = INT_MIN;
                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                        maxFreq = max(maxFreq, freq[k]);
                    }
                }
       return maxFreq-minFreq;
    }
    int beautySum(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum+=countfreq(s.substr(i,j-i+1));
            }
        }
      return sum;
    }
};