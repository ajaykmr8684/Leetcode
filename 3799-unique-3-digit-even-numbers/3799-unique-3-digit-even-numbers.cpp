class Solution {
public:
    int totalNumbers(vector<int>& A) {
        int N = A.size();
        int ans = 0;
        set<int> ts;
        for(int i=0; i<N; i++) {
            if(A[i] == 0) continue;

            for(int j=0; j<N; j++) {
                if(i==j) continue;

                for(int k=0; k<N; k++) {
                    if(j==k || i==k) continue;
                    if((A[k] % 2) != 0) continue;
                    ts.insert(A[i]*100 + A[j]*10 + A[k]);
                }
            }
        }

        return (int)ts.size();
    }
};