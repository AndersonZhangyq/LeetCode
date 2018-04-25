import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public String longestPalindrome(String s) {
        boolean[][] dp = new boolean[1001][1001];
        int length = s.length();
        for (int i = 0; i < length; i++) {
            dp[i][i] = true;
        }
        int max = 1;
        String longest = String.valueOf(s.charAt(0));
        for (int i = 0; i < length; i++) {
            if (i - 1 < 0)
                continue;
            for (int j = i - 1; j >= 0; j--) {
                if (s.charAt(j) == s.charAt(i) && (j == i - 1 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    int l = i - j + 1;
                    if (max < l) {
                        max = l;
                        longest = s.substring(j, i + 1);
                        System.out.println(j + "-" + i + ":" + longest);
                    }
                }
            }
        }
        return longest;
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            String s = get.next();
            System.out.println(new Solution().longestPalindrome(s));
        }
    }
}
