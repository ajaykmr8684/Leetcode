class Solution {
public:
    bool hasMatch(string s, string p) {
        int p_idx = p.find('*');
        
        string leftSubstring  = p.substr(0, p_idx);
        string rightSubstring = p.substr(p_idx + 1);
        cout << leftSubstring << endl;
        cout << rightSubstring;

        int lftIdx = s.find(leftSubstring);
        if(lftIdx == -1) return false; 
        int rightIndx = s.rfind(rightSubstring); 
        if(rightIndx == -1 ) return false;
        

        return lftIdx + leftSubstring.length() <= rightIndx;



        return true;  
    }
};