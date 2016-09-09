/*
copyright xu(xusiwei1236@163.com), all right reserved.

Minimum Size Subarray Sum
==========================

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.


For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.


click to show more practice.

More practice:

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/
import java.util.Random;
import java.util.Arrays;

public class Solution {
    // return the maxmium t, makes A[t] > target
    static int upper_bound(int target, int[] A, int left, int right) {
        int count = right - left + 1;
        while (count > 0) {
            int step = count / 2;
            if (A[left + step] <= target) {
                left  += step + 1;
                count -= step + 1;
            } else { // A[m] > target
                count = step;
            }
        }
        return left;
    }

    public int minSubArrayLen(int s, int[] A) {
        final int n = A.length;

        int sum[] = new int[n+1];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + A[i];
        }
        if (n == 0 || sum[n] < s) return 0;

        int result = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            if (sum[i] >= s) {
                int start = upper_bound(sum[i] - s, sum, 0, i-1);
                result = Integer.min(result, i - start + 1);
            }
        }
        return result == Integer.MAX_VALUE ? 0 : result;
    }

    public static void main(String[] args) {
        // test();
        int s = 7;
        int[] a = new int[]{2,3,1,2,4,3};
        if (args.length >= 1) s = Integer.parseInt(args[0]);
        if (args.length >= 2) {
            a = new int[args.length-1];
            for (int i = 0, c = 1; i < a.length; i++) {
                a[i] = Integer.parseInt(args[c++]);
            }
        }
        System.out.println(new Solution().minSubArrayLen(s, a));
    }

    static void print_upper_bound(int n, int[] a) {
        System.out.print(Arrays.toString(a) + "\t");
        System.out.printf("upper_bound(%d) = %d\n", n, upper_bound(n, a, 0, a.length-1));
    }

    static void test() {
        print_upper_bound(1, new int[]{0, 1, 1, 2, 4 ,5, 6});
        print_upper_bound(3, new int[]{0, 1, 1, 2, 4 ,5, 6});
        print_upper_bound(4, new int[]{0, 1, 1, 2, 4 ,5, 6});
        print_upper_bound(2, new int[]{2, 2, 2, 2, 2, 2, 2});
        print_upper_bound(0, new int[]{1, 2, 3, 4 ,5, 6, 7});
        print_upper_bound(8, new int[]{1, 2, 3, 4 ,5, 6, 7});
    }
}
