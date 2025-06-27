class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;
        string current;

        backtrack(0, digits, mapping, current, result);

        return result;
    }

    void backtrack(int index, const string &digits, const vector<string> &mapping,
                   string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(index + 1, digits, mapping, current, result);
            current.pop_back();
        }
    }
};
