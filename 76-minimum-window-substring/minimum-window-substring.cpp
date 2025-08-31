class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int i=0,j=0;
        int charcount=t.size();
        int stidx=-1;
        int minwind=INT_MAX;
        while(j<n){
            if(mp[s[j]]>0) charcount--;
            mp[s[j]]--;
            while(charcount==0){
               mp[s[i]]++;
               if(j-i+1<minwind){
                 minwind=j-i+1;
                 stidx=i;
               }
               if(mp[s[i]]>0)charcount++;
               i++;
            }
            j++;
        }
        return stidx==-1 ? "" : s.substr(stidx,minwind);
        
    }
};