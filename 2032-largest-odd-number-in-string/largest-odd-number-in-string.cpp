class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        // If the last digit is odd, return the whole number
        if ((num[n - 1] - '0') % 2 != 0) return num;

        // Search from the end for the first odd digit
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};
