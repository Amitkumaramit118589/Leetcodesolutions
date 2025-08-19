class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0;
        unordered_map<int,int> basket;
        int ans = 0;

        while (j < n) {
            basket[arr[j]]++;   // add current fruit

            // agar 2 se zyada types ho gayi to shrink window
            while (basket.size() > 2) {
                basket[arr[i]]--;
                if (basket[arr[i]] == 0) {
                    basket.erase(arr[i]);
                }
                i++;
            }

            ans = max(ans, j - i + 1); // valid window
            j++;
        }
        return ans;
    }
};