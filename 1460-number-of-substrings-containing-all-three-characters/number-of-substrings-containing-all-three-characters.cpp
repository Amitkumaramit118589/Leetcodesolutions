class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int count = 0;
        unordered_map<char, int> mp;

        while (j < n) {
            mp[s[j]]++; // Expand the window by including s[j]

            // Shrink the window until it contains all three characters
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                count += (n - j); // Add all substrings ending at j
                mp[s[i]]--;       // Shrink the window from the left
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]); // Remove character from map if count is 0
                }
                i++;
            }
            j++;
        }
        return count;
    }
};
