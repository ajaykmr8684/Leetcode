class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        vector<int> temp;

        for(int i =0; i<arr.size(); ++i){
            
            
          if(temp.size() < arr.size()){
              
              if(arr[i] == 0){
                  temp.push_back(arr[i]);
                  
                  if(temp.size() != arr.size()){
                      temp.push_back(arr[i]);
                  }
                  
                  
              }
              else{
                  temp.push_back(arr[i]);
                  
              }
              
              
          }
            else{
                
              break;
          }
            
        }
        
        
        arr = temp;
        
        
    }
};