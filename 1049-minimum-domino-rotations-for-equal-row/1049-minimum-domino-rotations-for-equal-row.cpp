class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> count(7, 0);
        for (int i=0;i<n;i++) {
            if (tops[i] == bottoms[i]) {
                count[tops[i]]++;
                continue;
            }
            count[tops[i]]++;
            count[bottoms[i]]++;
        }
        for (int i=1;i<=6;i++) {
            if (count[i] == n) {
                int res1 = 0, res2 = 0;
                for (int j=0;j<n;j++) {
                    if (tops[j] != i) res1++;
                    if (bottoms[j] != i) res2++;
                }
                return min(res1, res2);
            }
        }
        return -1;
    }
};