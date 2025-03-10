class Solution {
public:

    void solve(int n, string &curr, vector<string> &result) {
        if(curr.size() == n) {
            result.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ++ch) {
            if(!curr.empty() && curr.back() == ch) continue;

            //Do
            curr.push_back(ch);
            solve(n, curr, result);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> result;
        string curr = "";

        solve(n, curr, result);
        if(result.size() < k) return "";
        return result[k-1];
    }
};