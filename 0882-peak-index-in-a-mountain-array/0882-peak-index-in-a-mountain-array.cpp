class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid] < arr[mid -1]) r = mid;
            else l = mid + 1;
        }

        return -1;
    }
};