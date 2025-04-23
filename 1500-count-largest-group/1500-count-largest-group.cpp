class Solution {
public:
    int getSum(int n) {
        if(n <=9 ) return n;
        int temp = n;
        int sum = 0;
        while(temp) {
            int x = temp % 10;
            sum += x;
            temp /= 10;
        }

        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;

        for(int i = 1; i <= n; ++i) {
            int ans = getSum(i);
            mp[ans]++;
        }

        int maxi = 0, count = 0;
        for(auto it: mp) {
            if(it.second > maxi) maxi = it.second, count = 1;
            else if(it.second == maxi) count++;
        }

        return count;
    }
};