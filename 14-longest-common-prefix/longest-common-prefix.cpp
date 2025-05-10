class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        int len=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<strs.size();j++){
                string temp=strs[j];
                if(s[i]!=temp[i]) return s.substr(0,len);     
            }
            len++;
        }
        return s.substr(0,len);
    }
};