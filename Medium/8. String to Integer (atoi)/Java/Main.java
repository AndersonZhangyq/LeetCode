import java.util.Scanner;

class Solution {
    public int myAtoi(String str) {
        long ans = 0;
        boolean startConversion = false, isNeg = false;
        for (char c : str.toCharArray()){
            if (c == ' '){
                if (startConversion)
                    break;
            }else if (c>= '0' && c <= '9'){
                startConversion = true;
                ans = ans * 10 + (c- '0');
                if (ans > Integer.MAX_VALUE)
                    break;
            }else if (c == '+'){
                if (startConversion)
                    break;
                startConversion = true;
            }else if (c == '-'){
                if (startConversion)
                    break;
                startConversion = true;
                isNeg = true;
            }else
                break;
        }
        if (!startConversion)
            return 0;
        if (isNeg)
            ans = -ans;
        return ans > Integer.MAX_VALUE ? Integer.MAX_VALUE : (int) (ans < Integer.MIN_VALUE ? Integer.MIN_VALUE : ans);
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            String str = get.nextLine();
            System.out.println(new Solution().myAtoi(str));
        }
    }
}
