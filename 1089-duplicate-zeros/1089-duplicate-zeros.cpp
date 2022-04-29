class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        /* Represents start Pointer */
        int start = 0;
        
        while( start < arr.size()){
            
            if(arr[start] == 0){
                
            /* Use of inbuilt "insert" function to insert 0 in the
                position and shift latter elements to the right*/
                arr.insert(arr.begin() + start + 1, 0);
                
            /* Since we are maintaining the limited size of the array
                hence popping last element as soon as insert happens*/
                arr.pop_back();
                
                start++;
            }
            
            start++;
             
        }       
        
    }
};