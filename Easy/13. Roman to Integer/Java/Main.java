import jdk.nashorn.internal.ir.annotations.Immutable;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Solution {
    public int romanToInt(String s) {
        int length = s.length();
        if (length == 0)
            return -1;
        int i = 0;
        int ans = 0;
        char[] _1 = {'I', 'X', 'C', 'M'}, _5 = {'V', 'L', 'D'};
        Map<Character, Integer> letter = new HashMap<Character, Integer>() {{
            put('I', 0);
            put('V', 0);
            put('X', 1);
            put('L', 1);
            put('C', 2);
            put('D', 2);
            put('M', 3);
        }};
        Map<Character, Integer> num = new HashMap<Character, Integer>() {{
            put('I', 1);
            put('V', 5);
            put('X', 10);
            put('L', 50);
            put('C', 100);
            put('D', 500);
            put('M', 1000);
        }};
        while (i < length) {
            char cur = s.charAt(i);
            switch (cur) {
                case 'I':
                case 'X':
                case 'C':
                case 'M':{
                    int index = letter.get(cur);
                    int cur_num = num.get(cur);
                    if (i == length - 1){
                        ans += cur_num;
                        ++i;
                    }else{
                        ++i;
                        if (s.charAt(i) == cur){
                            ans += cur_num;
                            while(i < length && s.charAt(i) == cur){
                                ++i;
                                ans += cur_num;
                            }
                        }else if (index < 3 && s.charAt(i) == _5[index]){
                            ans += cur_num * 4;
                            ++i;
                        }else if (index < 3 && s.charAt(i) == _1[index + 1]){
                            ans += cur_num * 9;
                            ++i;
                        }else{
                            ans += cur_num;
                        }
                    }
                    break;
                }
                case 'V':
                case 'L':
                case 'D':{
                    int index = letter.get(cur);
                    int cur_num = num.get(cur);
                    if (i == length - 1) {
                        ans += cur_num;
                        ++i;
                    }else{
                        ans += cur_num;
                        ++i;
                        if (s.charAt(i) == _1[index]){
                            cur = s.charAt(i);
                            cur_num = cur_num / 5;
                            while(i < length && s.charAt(i) == cur){
                                ++i;
                                ans += cur_num;
                            }
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        while (true) {
            String s = get.next();
            System.out.println(new Solution().romanToInt(s));
        }
    }
}