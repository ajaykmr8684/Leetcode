class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> umap;
        int odd = INT_MIN;
        int even = INT_MAX;

        for(auto it: s)
        {
            umap[it]++;
        }

        for(auto it: umap)
        {   
            if(it.second & 1) {
                odd = max(it.second, odd);
            }
            else
            {
                even = min(it.second, even);
            }

        }

        return odd - even;
    }
};