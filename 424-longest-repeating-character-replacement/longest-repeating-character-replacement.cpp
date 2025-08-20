class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int l=0;
        int ans=0;
        int maxfreq=0;
        for(int r=0;r<s.size();r++){
           freq[s[r]-'A']++;
           maxfreq= max(freq[s[r]-'A'],maxfreq);
           while((r-l+1)-maxfreq >k){
            freq[s[l]-'A']--;
            l++;
           }
           ans=max(ans,r-l+1);
        }
        return ans;

    }
};