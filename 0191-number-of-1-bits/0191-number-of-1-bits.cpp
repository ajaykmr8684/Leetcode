class Solution {
public:
    int hammingWeight(int n) {
        int temp = n;
        int count = 0;

        while(temp) {
            int rem = temp % 2;
            if(rem == 1) count++;

            temp /= 2;
        }

        return count;
    }
};