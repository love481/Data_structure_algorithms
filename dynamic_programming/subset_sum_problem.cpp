#include<bits/stdc++.h>
using namespace std;
int possible_sum_subset(vector<int>&subset,int W)
{
   int dp[subset.size()+1][W+1];
   memset(dp,0,sizeof dp);
   for (int i=0;i<=subset.size();i++) dp[i][0]=1;
  
   for (int i=1;i<=subset.size();i++)
   {
    for (int j=1;j<W+1;j++)
    {
        if (dp[i-1][j]==1) dp[i][j]=dp[i-1][j];
        else if(j-subset[i-1]>=0)dp[i][j]=dp[i-1][j] | dp[i-1][j-subset[i-1]];
    }
   }
    for (int i=0;i<=subset.size();i++)
   {
    for (int j=0;j<W+1;j++)
    {
       cout<<dp[i][j]<<" ";
    }
    cout<<endl;
   }
   return dp[subset.size()][W];
}
int main(void)
{
    vector<int>subset{2,2,3,4};
    int W=6;
    if (possible_sum_subset(subset,W))
        cout<<"possible!"<<endl;
    else{
        cout<<"not possible!"<<endl;
    }

}