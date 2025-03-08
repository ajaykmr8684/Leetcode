class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;
        int j = 0;
        int n = blocks.length();

        int B_Count = 0;
        int windowSize = 0;
        int ans = INT_MAX;
        while(j < n) {
            windowSize = j - i + 1;
            if(blocks[j] == 'B') B_Count++;

            if(windowSize == k) {
                ans = min(ans, windowSize - B_Count);
                if(blocks[i] == 'B') {
                    B_Count--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};