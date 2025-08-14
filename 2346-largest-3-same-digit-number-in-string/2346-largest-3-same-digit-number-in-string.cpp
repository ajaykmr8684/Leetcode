class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        int i = 0, j = 1, k = 2;
        string ans = "";

        while(k < n) {
            if(num[i] == num[j] && num[i] == num[k] && num[j] == num[k]) {
                string temp = num.substr(i, 3);
                if(ans.empty() || temp > ans) {
                    ans =  temp;
                }
            }
            i++;
            j++;
            k++;
        }

        return ans;
    }
};