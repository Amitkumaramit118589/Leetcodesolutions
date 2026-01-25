class Solution {
    public int maxArea(int[] height) {
        int i=0;
        int j= height.length -1;
        int maxarea=0;

        while(i<j){
            int w=j-i;
            int h= Math.min(height[i],height[j]);
            int area= w*h;
            if(area>maxarea){
                maxarea=area;
            }
            if(height[i]>height[j]){
                j--;
            }
            else i++;
            
        }
        return maxarea;
    }
}