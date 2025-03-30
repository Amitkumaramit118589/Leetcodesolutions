class Solution {
public:
    int majorityElement(vector<int>& v) {
        map<int,int>mp;
	int n=v.size();
	if(n==1) return v[0];
	for(int i=0;i<n;i++){
		if(mp.find(v[i])!=mp.end()){
			 mp[v[i]]++;
			 if(mp[v[i]]>n/2)return v[i];
		}
		else{
			mp[v[i]]=1;
		}
	}
	return -1;
    }
};