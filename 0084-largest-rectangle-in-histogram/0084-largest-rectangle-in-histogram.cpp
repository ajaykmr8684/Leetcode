class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;

        vector<int> ls(heights.size());
        vector<int> rs(heights.size());

        //Filling Next smaller to the left
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if(st.empty()) ls[i] = 0;
            else ls[i] = st.top() + 1;
            st.push(i);
        }

        //Cleaning up the stack so that we can reuse it again
        while(!st.empty())
        {
            st.pop();
        }

        //Filling next smaller element to the right
        for(int i = heights.size()-1; i >= 0; --i)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if(st.empty()) rs[i] = heights.size() - 1;
            else rs[i] = st.top() - 1;
            st.push(i);
        }

        for(auto val: rs)
        {
            cout << val << " ";
        }


        int ans = 0;

        for(int i = 0; i < heights.size(); ++i)
        {
            ans = max(ans, (rs[i] - ls[i] + 1) * heights[i]);
        }

        return ans;

    }
};