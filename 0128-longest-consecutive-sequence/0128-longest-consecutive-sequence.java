class Solution {
    public int longestConsecutive(int[] arr) {
        int count = 1;
        int element = 0;
        int n = arr.length;
        if(n == 0)return 0;
        int res = Integer.MIN_VALUE;
        Arrays.sort(arr);
        for(int i=1;i<n;i++){
            if(arr[i-1] == arr[i]){
                continue;
            }else if(arr[i-1]+1 == arr[i]){
                count++;
            }else{
                res = Math.max(res, count);
                count = 1;
            }
        }
        res = Math.max(res, count);
        return res;
    }
}