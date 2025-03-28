/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int binarySearch(MountainArray &arr, int l, int r, int target) {
        int mid;
        
        while(l <= r){
            mid = l + (r - l) / 2;

            if(arr.get(mid) == target) return mid;
            else if(arr.get(mid) > target) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }

        int reverseBinarySearch(MountainArray &arr, int l, int r, int target) {
        int mid;
        
        while(l <= r){
            mid = l + (r - l) / 2;

            if(arr.get(mid) == target) return mid;
            else if(arr.get(mid) > target)   l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }


    int findPeak( MountainArray &arr) {
        int n = arr.length();
        int l = 0;
        int r = n - 1;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(arr.get(mid) < arr.get(mid+1)) l = mid + 1;
            else r = mid;
        }

        return l;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int idx = findPeak(arr);

        int result_idx = binarySearch(arr, 0, idx, target);

        if(result_idx != -1) {
            return result_idx;
        }

        return reverseBinarySearch(arr, idx, n - 1, target);


    }
};