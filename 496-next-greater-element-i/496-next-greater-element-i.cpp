class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> umap;
        
        
        for(int i = nums2.size()-1; i>=0; --i)
        {
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            
            if(!st.empty())
            {
                umap[nums2[i]] = st.top();
            }
            
            st.push(nums2[i]);
        }
        
        for(auto it: nums1)
        {
            if(umap.find(it) != umap.end()) ans.push_back(umap[it]);
            else ans.push_back(-1);
            
        }
        
        
       return ans; 
    }
};