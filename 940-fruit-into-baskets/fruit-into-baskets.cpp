class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        map<int,int>mp;
        int cnt=0;
        while(j<fruits.size()){
             mp[fruits[j]]++;
              while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
              }
              cnt=max(cnt,j-i+1);
              
              j++;
             
              
        }
        return cnt;
    }
};