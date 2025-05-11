class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>arr(26,0);
        vector<int>brr(26,0);
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            arr[ch-'a']++;
        }
        for(int j=0;j<t.size();j++){
            char ch=t[j];
            brr[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=brr[i])return false;
        }
        return true;

    }
};