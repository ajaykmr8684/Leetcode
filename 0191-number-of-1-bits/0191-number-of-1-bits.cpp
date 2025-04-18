class Solution {
public:
    int hammingWeight(int n) {
        int temp = n;
        int count = 0;


        // Brian Kernighan’s Algorithm ( Just AND it with lower number and you will get rid of the precedence 1)
        while(temp) {
            temp = temp & temp-1;
            count++;
            
        }

        return count;
    }
};