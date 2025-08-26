class Solution {
public:
    double findDiagonalLength(int length, int width) {
        return sqrt(length * length + width * width);
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        double diagLen = 0.0;

        for(int i = 0; i < dimensions.size(); ++i) {
            int len  = dimensions[i][0];
            int wid  = dimensions[i][1];
            int area = len * wid;

            double currDiagLen = findDiagonalLength(len, wid);
            if(currDiagLen > diagLen) {
                diagLen = currDiagLen;
                ans = area;
            }

            if(currDiagLen == diagLen) {
                ans = max(ans, area);
            }
        }

        return ans;
    }
};
