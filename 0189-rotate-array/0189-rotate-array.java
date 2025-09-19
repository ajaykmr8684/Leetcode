class Solution {
    public void rotate(int[] nums, int d) {
        int n=nums.length;
        d=d%nums.length;
        revers(nums,0,n-1);
        revers(nums,0, d-1);
        revers(nums,d,n-1);
    }

    static void revers(int arr[], int i, int j){
        while(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
}