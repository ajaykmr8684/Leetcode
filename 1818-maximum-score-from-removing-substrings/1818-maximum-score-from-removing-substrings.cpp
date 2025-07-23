class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        stack<char> q;
        char first = 'a';
        char second = 'b';
        if (y > x) {
            swap(first, second);
            swap(x, y);
        }

        for (auto c : s) {
            if (c == second) {
                if (!q.empty() && q.top() == first) {
                    ans += x;
                    q.pop();
                } else {
                    q.push(c);
                }
            } else if (c == first) {
                q.push(c);
            } else {
                int count = 0;
                while (!q.empty()) {
                    if (q.top() == first)
                        count++;
                    else {
                        if (count > 0) {
                            ans += y;
                            count--;
                        }
                    }
                    q.pop();
                }
            }
        }
        int count = 0;
        while (!q.empty()) {
            if (q.top() == first)
                count++;
            else {
                if (count > 0) {
                    ans += y;
                    count--;
                }
            }
            q.pop();
        }

        return ans;
    }
};