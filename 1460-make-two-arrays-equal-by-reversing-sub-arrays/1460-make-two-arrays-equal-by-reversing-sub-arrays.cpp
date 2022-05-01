class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        unordered_map<int, int> umap1;
        // unordered_map<int, int> umap2;
        
        for(int i = 0; i< target.size(); ++i){
            umap1[target[i]]++;
            // umap2[target[i]]++;
        }
        
        // if(umap1 == umap2) return true;
        // return false;
        
        for(auto it: arr){
            umap1[it]--;
            if(umap1[it] == 0){
                umap1.erase(it);
            }
        }
        
        for(auto it: umap1){
            cout << it.first << " " << it.second << endl;
        }
        
        //cout << umap1.size() << endl;
        if(umap1.size() == 0) return true;
        
        
        return false;;
    }
};