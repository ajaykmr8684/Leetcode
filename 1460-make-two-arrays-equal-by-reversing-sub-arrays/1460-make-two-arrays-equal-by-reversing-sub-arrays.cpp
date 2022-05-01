class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        unordered_map<int, int> umap1;
        unordered_map<int, int> umap2;
        
        for(int i = 0; i< target.size(); ++i){
            umap1[arr[i]]++;
            umap2[target[i]]++;
        }
        
        if(umap1 == umap2) return true;
        return false;
        
    }
};