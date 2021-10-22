class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1],need;
       for(int i=0;i<=n;i++){
           dp[i][0]=0;
       }
       for(int i=0;i<=n;i++){
           dp[0][i]=0;
       }
       
       for(int i = 1 ; i<=n ; i++){
           for(int j = 1 ; j<=W;j++){
               if(j<wt[i-1]){
                   dp[i][j] = dp[i-1][j];
               }
               else{
                   need = j - wt[i-1];
                   dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][need]);
               }
           }
       }
       return dp[n][W];
    }
};