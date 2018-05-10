import java.util.Scanner;

class Solution {
    public String intToRoman(int num) {
        if (num < 1 || num > 3999)
            return "";
        String[] _1 = {"I", "X", "C", "M"}, _5 = {"V", "L", "D"};
        StringBuilder ans = new StringBuilder();
        int i = 0;
        while (num != 0) {
            int digit = num % 10;
            switch (digit) {
                case 1:
                case 2:
                case 3:
                    for (int j = 0; j < digit; j++) {
                        ans = ans.insert(0, _1[i]);
                    }
                    break;
                case 4:
                    ans = ans.insert(0, _1[i] + _5[i]);
                    break;
                case 5:
                    ans = ans.insert(0, _5[i]);
                    break;
                case 6:
                case 7:
                case 8:
                    for (int j = 5; j < digit; j++) {
                        ans = ans.insert(0, _1[i]);
                    }
                    ans = ans.insert(0, _5[i]);
                    break;
                case 9:
                    ans = ans.insert(0, _1[i] + _1[i + 1]);
                    break;
            }
            num = num / 10;
            ++i;
        }
        return ans.toString();
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            int num = get.nextInt();
            System.out.println(new Solution().intToRoman(num));
        }
    }
}
