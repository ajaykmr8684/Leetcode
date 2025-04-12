class Solution {
public:
    bool isPalindrome(int x) {
        //just reverse the x, and match against it;

        long newNum = 0;
        int temp = x;

        if(x >= 0) {
            while(temp) {
                int t = temp % 10;
                newNum = newNum * 10+t;
                temp /= 10;
            }

            return x == newNum;
        }

        return false;
    }
};