import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int length = s.length();
        if (length <= 1)
            return length;
        int[] allLetter = new int[Character.MAX_VALUE];
        Arrays.fill(allLetter, -1);
        int from = 0, max = 1;
        allLetter[(int) s.charAt(0)] = 0;
        for (int i = 1; i < length; i++) {
            int cur_char = (int)s.charAt(i);
            if (allLetter[cur_char] == -1){
                allLetter[cur_char] = i;
            }else{
                int cur_length = i - from;
                max = max < cur_length ? cur_length : max;
                // @@ 再次踩坑，一定要多注意！！！
                from = from < allLetter[cur_char] + 1 ? allLetter[cur_char] + 1 : from;
                allLetter[cur_char] = i;
            }
        }
        max = max < length - from ? length - from : max;
        return max;
    }
}


public class Main{
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while(true){
            String s = get.next();
            System.out.println(new Solution().lengthOfLongestSubstring(s));
        }
    }
}
