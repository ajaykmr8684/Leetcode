class Solution {
public:
    int trap(vector<int>& height) {
        int maxi=INT_MIN;
        
        //fill the array from 0 to n
        vector<int> a(height.size());
        
        for(int i=0; i<height.size(); ++i){
            maxi = max(maxi, height[i]);
            a[i] = maxi;
        }
        
        
        //fill the array from n to 0
        
         vector<int> b(height.size());
        maxi = INT_MIN;
        for(int i=height.size()-1; i>=0; --i){
            maxi = max(maxi, height[i]);
            b[i] = maxi;
        }
        
        int sum=0;
        for(int i=0; i<height.size(); ++i){
            
            sum += min(a[i], b[i]) - height[i];
            
            
        }
        
       
        return sum;
    }
};