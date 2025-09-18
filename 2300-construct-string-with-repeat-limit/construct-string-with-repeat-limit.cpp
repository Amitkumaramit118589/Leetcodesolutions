class Solution {
public:
    string repeatLimitedString(string s, int repeatlt) {
        map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<pair<char,int>>pq;
        for(auto i:mp){
            pq.push({i.first,i.second});
        }
        string result="";
        while(!pq.empty()){
            auto largest=pq.top();
            pq.pop();
            int len=min(largest.second,repeatlt);
            for(int i=0;i<len;i++){
                result+=largest.first;
            }
             
            if(largest.second-len>0){
            if(!pq.empty()){
                auto secondlar = pq.top();
                pq.pop();
                result += secondlar.first;

                pq.push({largest.first, largest.second - len});
                
                if(secondlar.second - 1 > 0) pq.push({secondlar.first, secondlar.second - 1});
            }
            else return result;
            }

        }
        return result;
        
    }
};
