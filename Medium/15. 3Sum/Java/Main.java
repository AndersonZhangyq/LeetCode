import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int length = nums.length;
        if (length < 3)
            return ans;
        Arrays.sort(nums);
        int i = 0;
        while (i < length - 2) {
            int cur_i = nums[i];
            int start = i + 1, end = length - 1;
            while (start < end) {
                int s = nums[start], e = nums[end];
                int sum = cur_i + s + e;
                if (sum == 0) {
                    ans.add(Arrays.asList(cur_i, s, e));
                    ++start;
                    while (start < end && nums[start] == s)
                        ++start;
                    --end;
                    while (start < end && nums[end] == e)
                        --end;
                }else if (sum > 0){
                    --end;
                    while (start < end && nums[end] == e)
                        --end;
                }else{
                    ++start;
                    while (start < end && nums[start] == s)
                        ++start;
                }
            }
            ++i;
            while (i < length - 2 && nums[i] == cur_i)
                ++i;
        }
        return ans;
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            String data = get.nextLine();
            String[] strs = data.split(" ");
            int[] nums = new int[strs.length];
            for (int i = 0; i < strs.length; i++) {
                nums[i] = Integer.valueOf(strs[i]);
            }
            List<List<Integer>> ans = new Solution().threeSum(nums);
            for (List<Integer> r : ans) {
                for (Integer e : r) {
                    System.out.printf("%d ", e);
                }
                System.out.println();
            }
        }
    }
}