class Solution {
    public String reverseWords(String s) {
        int i = s.length() - 1;
        StringBuilder ans = new StringBuilder();

        while (i >= 0) {
            // skip spaces
            while (i >= 0 && s.charAt(i) == ' ') i--;
            if (i < 0) break;

            int j = i;
            // find start of word
            while (j >= 0 && s.charAt(j) != ' ') j--;

            // append the word
            ans.append(s.substring(j + 1, i + 1));
            ans.append(" ");

            i = j;
        }

        // remove last extra space
        return ans.toString().trim();
    }
}
