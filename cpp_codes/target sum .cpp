//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        int sum=0;
        for(int i=0;i<A.size();i++)sum+=A[i];
        
    int s1= (target+sum)/2;
    

        if((target+sum)%2!=0) //if its odd we will get fractional s1 which is not possible.
            return 0;
    
    int dp[A.size()+1][s1+1];
    for(int i=0;i<A.size()+1;i++)dp[i][0]=1;
    for(int i=1;i<s1+1;i++)dp[0][i]=0;
    
    for(int i=1;i<A.size()+1;i++)
    {
        for(int j=1;j<s1+1;j++)
        {
            if(A[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-A[i-1]];
                
                
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[A.size()][s1];
    
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends