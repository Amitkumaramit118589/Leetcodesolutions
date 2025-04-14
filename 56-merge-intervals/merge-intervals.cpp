class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int i = 0;
    vector<int> temp(2, -1);
    temp[0] = arr[0][0]; // starting
    temp[1] = arr[0][1];

    while (i + 1 < arr.size()) {
        //  compare with temp, not arr[i]
        if (temp[1] >= arr[i + 1][0]) {
            temp[1] = max(temp[1], arr[i + 1][1]);
        } else {
            ans.push_back(temp);
            temp[0] = arr[i + 1][0];
            temp[1] = arr[i + 1][1];
        }
        i++;
    }

    ans.push_back(temp);
    return ans;
}
};