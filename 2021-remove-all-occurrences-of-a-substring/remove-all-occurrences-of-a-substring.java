class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder ans = new StringBuilder();
        int n = part.length();

        for (char ch : s.toCharArray()) {
            ans.append(ch);

            // if the ending matches part remove it
            if (ans.length() >= n &&
                ans.substring(ans.length() - n).equals(part)) {
                ans.delete(ans.length() - n, ans.length());
            }
        }

        return ans.toString();
    }
}
