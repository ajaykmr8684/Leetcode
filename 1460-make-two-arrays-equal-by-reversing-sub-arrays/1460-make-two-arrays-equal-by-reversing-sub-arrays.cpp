class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        unordered_map<int, int> umap1;
        
        for(int i = 0; i< target.size(); ++i){
            umap1[target[i]]++;
        }
        
        for(auto it: arr){
            umap1[it]--;
            
            if(umap1[it] == 0){
                umap1.erase(it);
            }
        }

        if(umap1.size() == 0) return true;
        
        return false;;
    }
};