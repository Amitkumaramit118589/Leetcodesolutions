class Solution {
public:
    int maxDepth(string s) {
        int ob=0;
        int cb=0;
        int maxb=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') ob++;
            if(s[i]==')') ob--;
            maxb=max(ob,maxb);
        }
        return maxb;
    }
};