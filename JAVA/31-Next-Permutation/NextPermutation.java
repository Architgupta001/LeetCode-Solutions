import java.util.*;

class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        int check = nums[len - 1];
        boolean isCheck = false;
        int reverseStartIndex = len - 1;
        for (int i = len - 2; i >= 0; i--) { // 배열 탐색
            reverseStartIndex--;
            if (check > nums[i]) {
                isCheck = true;
                for (int j = len - 1; j >= i; j--) {
                    if (nums[i] < nums[j]) {
                        System.out.println("i: " + i + ", j: " + j);
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
                break;
            }
            check = nums[i];
        }
        for (int i = 0; i < len; i++) {
            System.out.println("nums[" + i + "]: " + nums[i]);
        }
        if (!isCheck) { // 역순 입력
            reverseStartIndex--;
        }
        nums = reverse(reverseStartIndex + 1, nums);
        System.out.println(reverseStartIndex);
    }

    private int[] reverse(int start, int[] arr) {
        int len = arr.length;
        int i = start, j = len - 1;
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        return arr;
    }
}
