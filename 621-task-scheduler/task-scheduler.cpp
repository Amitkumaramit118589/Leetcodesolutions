#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequencies of tasks
        unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        // Step 2: Push frequencies in max-heap
        priority_queue<int> pq;
        for (auto &it : freq) {
            pq.push(it.second);
        }

        int time = 0;

        // Step 3: Process until heap is empty
        while (!pq.empty()) {
            vector<int> temp;  // store tasks of this cycle
            int cycle = n + 1; // length of one cycle

            // Step 3.1: Pick up to n+1 tasks
            while (cycle > 0 && !pq.empty()) {
                int cnt = pq.top(); pq.pop();
                if (cnt > 1) temp.push_back(cnt - 1); // task still left
                time++; // we used 1 interval
                cycle--;
            }

            // Step 3.2: Push remaining tasks back to heap
            for (int cnt : temp) {
                pq.push(cnt);
            }

            // Step 3.3: If heap not empty, need to fill cycle with idles
            if (!pq.empty()) {
                time += cycle; // add idle slots
            }
        }

        return time;
    }
};
