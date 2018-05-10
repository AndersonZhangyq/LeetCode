import java.util.Scanner;

class Solution {
    public int maxArea(int[] height) {
        if (height.length <= 1)
            return -1;
        if (height.length == 2)
            return height[0] < height[1] ? height[0] : height[1];
        int ans = -1;
        int left = 0, right = height.length - 1;
        while(left < right){
            int h = height[left] < height[right] ? height[left] : height[right];
            int area = h * (right - left);
            ans = ans < area ? area : ans;
            if (h == height[left])
                ++left;
            else
                --right;
        }
        return ans;
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            String data = get.nextLine();
            String[] heights = data.split(" ");
            int[] height = new int[heights.length];
            for (int i = 0; i < heights.length; i++) {
                height[i] = Integer.valueOf(heights[i]);
            }
            System.out.println(new Solution().maxArea(height));
        }
    }
}
