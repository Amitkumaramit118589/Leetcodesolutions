class Solution {
    public int largestRectangleArea(int[] heights)
    {
        int left[]=previousSmaller(heights);
        int right[]=nextSmaller(heights);
        int maxArea=0;

        for(int i=0;i<heights.length;i++)
        {
            int width=right[i]-left[i]-1;
            int area=heights[i]*width;
            maxArea=Math.max(area,maxArea);
        }

        return maxArea;
    }

    private int[] nextSmaller(int nums[])
    {
        Stack<Integer> st=new Stack<>();
        int ans[]=new int[nums.length];
        for(int i=ans.length-1;i>=0;i--)
        {
            while(!st.isEmpty() && nums[st.peek()]>=nums[i])
            {
                st.pop();
            }
            if(st.isEmpty())
            {
                ans[i]=ans.length;
            }
            else 
            {
                ans[i]=st.peek();
            }

            st.push(i);
        }
        return ans;
    }

    private int[] previousSmaller(int nums[])
    {
            Stack<Integer> st=new Stack<>();
            int ans[]=new int[nums.length];
            for(int i=0;i<ans.length;i++)
            {
                while(!st.isEmpty() && nums[st.peek()]>=nums[i])
                {
                    st.pop();
                }
                if(st.isEmpty())
                {
                    ans[i]=-1;
                }
                else 
                {
                    ans[i]=st.peek();
                }

                st.push(i);
            }
            return ans;
    }
}