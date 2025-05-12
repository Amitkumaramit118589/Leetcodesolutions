class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {0}; // 128 size le liya ASCII characters ke liye

        // Step 1: Count frequency of each character
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        // Step 2: Store characters in a vector
        vector<char> chars;
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                chars.push_back((char)i);
            }
        }

        // Step 3: Sort characters based on frequency (descending)
        sort(chars.begin(), chars.end(), [&](char a, char b) {
            return freq[a] > freq[b];
        });

        // Step 4: Create the answer string
        string ans = "";
        for (int i = 0; i < chars.size(); i++) {
            char ch = chars[i];
            for (int j = 0; j < freq[ch]; j++) {
                ans += ch;
            }
        }

        return ans;
    }
};
