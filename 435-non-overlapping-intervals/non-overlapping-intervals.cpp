class Solution {
private:
    bool static comparator(vector<int>& val1, vector<int>& val2) {
        return val1[1] < val2[1]; // sorting by end time
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparator);
        int count = 1;
        int endindexvalue = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= endindexvalue) {
                count++;
                endindexvalue = intervals[i][1];
            }
        }
        return n - count;
    }
};