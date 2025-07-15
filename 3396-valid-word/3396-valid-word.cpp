class Solution {
public:
    bool isValid(string word) {
        bool ans = false;
        int vowels = 0;
        int consts = 0;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        if(word.length() < 3) return false;


        for(int i = 0; i < word.length(); ++i) {
            if(isalpha(word[i])){
               if(st.find(word[i]) != st.end()) vowels++;
            else consts++; 
            }
            else if(!isdigit(word[i])) return false;
            
        }

        return vowels >= 1 && consts >= 1;
        
    }
};