class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
            int n = s.length();
            vector<int> diff(n);

            for(auto query: shifts)
            {
                int L = query[0];
                int R = query[1];
                int x = query[2] == 0 ? -1 : 1;

                // Updating diff array
                diff[L]   += x;
                if(R + 1 < n) diff[R+1] -= x;
            }

            //Finding cummulative sum
            for(int i = 1; i < n; ++i) {
                diff[i] += diff[i-1];
            }

            //Applying shift change
            for(int i = 0; i < n; ++i)
            {
                int shift = diff[i] % 26;
                if(shift < 0) shift += 26;

                s[i] = ((s[i] - 'a' + shift) % 26) + 'a';

            }
        return s;
    }
};