import java.util.HashMap;

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();

        int i = 0, j = 0;
        int sum = 0;
        int ans = Integer.MIN_VALUE;

        while (j < n) {
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            
            while (map.get(nums[j]) > 1) {
                map.put(nums[i], map.get(nums[i]) - 1);
                sum -= nums[i];
                i++;
            }

            sum += nums[j];
            ans = Math.max(ans, sum);
            j++;
        }

        return ans;
    }
}
