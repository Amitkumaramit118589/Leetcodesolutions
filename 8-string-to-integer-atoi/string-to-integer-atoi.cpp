class Solution {
public:
    void help(string s, int i, int n ,long long &ans){
         if (i >= n || !isdigit(s[i])) return;

        int digit = s[i] - '0';

        // Overflow check before applying
        if (ans > (LLONG_MAX - digit) / 10) return;

        ans = ans * 10 + digit;

        help(s, i + 1, n, ans);
    }
    int myAtoi(string s) {
        int n= s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n && (s[i]=='-'|| s[i]=='+')){
            if(s[i]=='-')sign*=-1;
            i++;
        }
        long long ans=0;
        help(s,i,n,ans);
        ans*=sign;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};