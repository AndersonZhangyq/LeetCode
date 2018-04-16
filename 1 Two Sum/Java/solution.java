import java.util.*;

class Solution {
    class MyPair implements Comparable<MyPair> {
        public int getA() {
            return a;
        }

        public int getB() {
            return b;
        }

        int a;

        int b;

        public MyPair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(MyPair myPair) {
            return this.a - myPair.getA();
        }
    }

    /*public int[] twoSum(int[] nums, int target) {
        int length = nums.length;
        if (length <= 1)
            return new int[]{};
        List<MyPair> all = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            all.add(new MyPair(nums[i], i));
        }
        Collections.sort(all);
        for (int i = 0, j = length - 1; i < j && i < length; ) {
            int sum = all.get(i).getA() + all.get(j).getA();
            if (sum == target) {
                int a = all.get(i).getB(), b = all.get(j).getB();
                if (a > b) {
                    int t = a;
                    a = b;
                    b = t;
                }
                return new int[]{a, b};
            } else if (sum > target)
                --j;
            else
                ++i;
        }
        return new int[]{};
    }*/

    /**
     * 使用 Map，查找是否存在和当前元素相加为目标值的元素
     */
    public int[] twoSum_(int[] nums, int target) {
        int length = nums.length;
        if (length <= 1)
            return new int[]{};
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < length; i++) {
            map.put(nums[i], i);
        }
        for (int i = 0; i < length; i++) {
            int left = target - nums[i];
            if (map.containsKey(left) && map.get(left) != i){
                return new int[]{i, map.get(left)};
            }
        }
        return new int[]{};
    }
}

public class Main {

    public static void main(String args[]) {
        Scanner get = new Scanner(System.in);
        int size;
        while (true) {
            size = get.nextInt();
            int nums[] = new int[size];
            for (int i = 0; i < size; i++) {
                nums[i] = get.nextInt();
            }
            int target = get.nextInt();
            int ans[] = new Solution().twoSum(nums, target);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}
