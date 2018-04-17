import java.util.Scanner;
import java.util.Stack;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;
        ListNode head = new ListNode(0);
        ListNode cur = head;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int a = l1 == null ? 0 : l1.val,
                    b = l2 == null ? 0 : l2.val;
            int sum = a + b + carry;
            cur.next = new ListNode(sum % 10);
            cur = cur.next;
            carry = sum / 10;
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
        }
        if (carry != 0) {
            cur.next = new ListNode(carry);
        }
        return head.next;
    }
}


public class Main {
    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        int size_1, size_2;
        while (true) {
            size_1 = get.nextInt();
            ListNode l1 = null, l2 = null, move_1 = null, move_2 = null;
            for (int i = 0; i < size_1; i++) {
                int tmp = get.nextInt();
                if (l1 == null) {
                    l1 = new ListNode(tmp);
                    move_1 = l1;
                } else {
                    move_1.next = new ListNode(tmp);
                    move_1 = move_1.next;
                }
            }
            size_2 = get.nextInt();
            for (int i = 0; i < size_2; i++) {
                int tmp = get.nextInt();
                if (l2 == null) {
                    l2 = new ListNode(tmp);
                    move_2 = l2;
                } else {
                    move_2.next = new ListNode(tmp);
                    move_2 = move_2.next;
                }
            }
            ListNode ans = new Solution().addTwoNumbers(l1, l2);
            Stack<Integer> result = new Stack<>();
            while (ans != null) {
                result.push(ans.val);
                ans = ans.next;
            }
            while (!result.empty()) {
                System.out.print(result.pop());
            }
            System.out.println();
        }
    }
}