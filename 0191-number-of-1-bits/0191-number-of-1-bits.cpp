class Solution {
public:
    int hammingWeight(int n) {
        int temp = n;
        int count = 0;

        while(temp) {
            temp = temp & temp-1;
            count++;
            
        }

        return count;
    }
};