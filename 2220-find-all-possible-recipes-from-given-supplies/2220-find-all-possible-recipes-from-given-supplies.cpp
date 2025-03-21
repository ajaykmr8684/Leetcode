class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ings, vector<string>& supplies) {
        unordered_set<string> st(begin(supplies), end(supplies));
        int n = recipes.size();
        int count = n;
        vector<string> result;

        vector<bool> cooked(n, false);
        while(count--) {
            for(int j = 0; j < n; ++j) {
                if(cooked[j]) continue;
                bool isPossible = true;

                for(int k = 0; k < ings[j].size(); ++k) {
                    if(!st.count(ings[j][k])) {
                        isPossible = false;
                        break;
                    }
                }

                if(isPossible) {
                    st.insert(recipes[j]);
                    result.push_back(recipes[j]);
                    cooked[j] = true;
                }
            }
        }

        return result;
    }
};