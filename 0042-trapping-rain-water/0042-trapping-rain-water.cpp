class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);
        int sum = 0;

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        //populate leftMax
        for(int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        //populate rightMax
         for(int i = n-2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        for(int i = 0; i < n; ++i) {
            int h = min(leftMax[i], rightMax[i]) - height[i];
            sum += h;
        }

        return sum;


    }
};