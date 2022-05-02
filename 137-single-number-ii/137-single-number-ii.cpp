class Solution {
    
private:
    
    void addToBits(vector<int> &bits, int n){
        
        for(int i =0; i<32; ++i){
            
            int iBit = n & (1 << i);
            
            if(iBit) bits[i]++;
            
        }
        
        
    }
    
    int binaryToDecimal(vector<int> bits){
        
        int sum = 0;
        
        for(int i =0; i<32; ++i){
            
            sum += (bits[i] * (1 << i));
            
        }
        
        return sum;
  
        
    }

    
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> bits(32, 0);
        
        for(auto it: nums){
            
            addToBits(bits, it);
            
        }
        
        for(int i=0; i<32; ++i){
            
            bits[i] = bits[i] % 3;
                  
        } 
        
        return binaryToDecimal(bits);
        
    }
};