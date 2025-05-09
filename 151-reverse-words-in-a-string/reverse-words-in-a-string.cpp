class Solution {
public:
    string reverseWords(string s) {
        int i=s.length()-1;
        string ans="";
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            int j=i;
            while(j>=0 && s[j]!=' '){
                j--;
            }
            
            ans+=s.substr(j+1,i-j);
            i=j;
            ans+=" ";

        }
        while(ans!="" && ans.back()==' ') ans.pop_back();
        
        return ans;
    }
};