import java.util.Scanner;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
            return "";
        if (strs.length == 1)
            return strs[0];
        String base = strs[0];
        int l = base.length();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < l; ++i){
            char cur = base.charAt(i);
            for (String s : strs){
                if (i == s.length())
                    return ans.toString();
                if (s.charAt(i) != cur)
                    return ans.toString();
            }
            ans.append(cur);
        }
        return ans.toString();
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            String s = get.nextLine();
            String[] strs = s.split(" ");
            System.out.println(new Solution().longestCommonPrefix(strs));
        }
    }
}