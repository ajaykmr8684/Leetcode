// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
    //Code here
    unordered_map<int, pair<int, int>> els;
    
    for(int i = 0; i < n; ++i ){
        
        if(els.find(arr[i]) == els.end()){
            els[arr[i]] = {i,i};
        }
        else {
            //This is where the magic happens
            auto &it = els[arr[i]];
            it.second =  i;
            //cout <<"console--> " <<it.second << endl ;
            //it.second =  i;
        }
        
    }
    
    int maxi = INT_MIN;
    
    for(auto it: els){
        maxi = max(it.second.second - it.second.first, maxi );
    }
        
         return maxi;
        
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends