import java.util.Scanner;

class Solution {
    public int reverse(int x) {
        long ans = 0;
        boolean isNeg = false;
        if (x < 0){
            isNeg = true;
            x = -x;
        }
        if (x == Integer.MIN_VALUE)
            return 0;
        while(x != 0){
            int digit = x % 10;
            x = x / 10;
            ans = ans * 10 + digit;
            if (ans > Integer.MAX_VALUE)
                return 0;
        }
        if (isNeg)
            ans = -ans;
        return ans > Integer.MAX_VALUE ? 0 : (int) (ans < Integer.MIN_VALUE ? 0 : ans);
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            int x = get.nextInt();
            System.out.println(new Solution().reverse(x));
        }
    }
}
