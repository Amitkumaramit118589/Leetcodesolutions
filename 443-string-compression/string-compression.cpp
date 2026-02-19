class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        int index=0;
        while(i<n){
            char curr= chars[i];
            int count=0;

            while(i<n && chars[i]==curr){
                i++;
                count++;
            }
            chars[index++]=curr;

            if(count>1){
               string s= to_string(count);
               for(char c : s){
                chars[index++]=c;
               }
            }
        }
        return index;
    }
};