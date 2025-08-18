class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> freq(256, -1); // ASCII chars ke liye last index
        int left = 0, ans = 0;

        for (int right = 0; right < n; right++) {
            char c = s[right];

            // Agar duplicate mila aur uska index current window ke andar hai
            if (freq[c] >= left) {
                left = freq[c] + 1;  // window shrink karo
            }

            freq[c] = right; // last index update
            ans = max(ans, right - left + 1); // max window size
        }
        return ans;
    }
};