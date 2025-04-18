class Solution {
public:
    int hammingWeight(int n) {
        int temp = n;
        int count = 0;

        while(temp) {
            if(temp & 1 == 1) count++;
            temp = temp >> 1;
            
        }

        return count;
    }
};