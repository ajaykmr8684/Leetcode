class Solution {
public:
    string pushDominoes(string doms) {
        int n = doms.length();
        vector<int> leftNearestR(n);
        vector<int> rightNearestL(n);


        //Left to Right -> R
        for(int i = 0; i < n; ++i) {
            if(doms[i] == 'R') {
                leftNearestR[i] = i;
            }
            else if(doms[i] == '.') {
                leftNearestR[i] = i > 0 ? leftNearestR[i-1] : -1;
            }
            else {
                leftNearestR[i] = -1;
            }
        }

        // Right to left -> L
        for(int i = n-1; i >= 0; --i) {
            if(doms[i] == 'L') {
                rightNearestL[i] = i;
            }
            else if(doms[i] == '.') {
                rightNearestL[i] = i < n-1 ? rightNearestL[i+1] : -1;
            }
            else {
                rightNearestL[i] = -1;
            }
        }

        //Compute the impact
        string result(n , ' ');
        for(int i = 0; i < n; ++i) {
            int distRightL = abs(i - rightNearestL[i]);
            int distLeftR = abs(i - leftNearestR[i]);

            if(rightNearestL[i] == leftNearestR[i]) {
                result[i] = '.';
            }
            else if(rightNearestL[i] == -1) {
                result[i] = 'R';
            }
            else if(leftNearestR[i] == -1) {
                result[i] = 'L';
            }
            else if(distRightL == distLeftR) {
                result[i] = '.';
            }
            else {
                result[i] = distRightL < distLeftR ? 'L' : 'R';
            }
        }

        return result;
    }
};