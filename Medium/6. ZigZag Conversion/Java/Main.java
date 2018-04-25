import java.util.Scanner;

class Solution {
    public String convert(String s, int numRows) {
        int length = s.length();
        if (length <= 0 || numRows <= 0)
            return "";
        if (numRows == 1)
            return s;
        char[][] zigzag = new char[numRows][length];
        boolean goDown = false, first = true;
        int i = 0, j = 0, s_i = 0;
        while (s_i < length) {
            zigzag[i][j] = s.charAt(s_i);
            if (first) {
                first = false;
            }
            if (goDown) {
                if (i + 1 == numRows) {
                    goDown = false;
                    --i;
                    ++j;
                } else {
                    ++i;
                }
            } else {
                if (i == 0) {
                    goDown = true;
                    ++i;
                } else {
                    --i;
                    ++j;
                }
            }
            s_i++;
        }
        StringBuffer ans = new StringBuffer();
        for (int k = 0; k < numRows; k++) {
            for (int l = 0; l < length; l++) {
                if (zigzag[k][l] != 0){
                    ans.append(zigzag[k][l]);
                }
            }
        }
        return ans.toString();
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            String s = get.next();
            int numRows = get.nextInt();
            System.out.println(new Solution().convert(s, numRows));
        }
    }
}
