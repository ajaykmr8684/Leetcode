class Solution {
    
private:
    
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
public:
    void sortColors(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int z = nums.size() -1;
        
        while(i <= z){
            
            if(nums[i] == 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if(nums[i] == 1){
                i++;
            }
            else{
                swap(nums[i], nums[z]);
                z--;
            }
                        
        }
   
        
    }
};