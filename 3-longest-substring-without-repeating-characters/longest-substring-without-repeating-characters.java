class Solution {
    public int lengthOfLongestSubstring(String s) {
            if(s.length()==0) return 0;
            int ans = 1;
            HashSet<Character> set = new HashSet<>();
            int left = 0, right = 0;
            while (right < s.length()) {
                if (set.contains(s.charAt(right))) {
                    set.remove(s.charAt(left));
                    left++;
                } else {
                    set.add(s.charAt(right));
                    right++;
                    int sz = set.size();
                    ans = Math.max(ans, sz);
                }
            }

            return ans;
        
    }
}