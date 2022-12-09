#include<bits/stdc++.h>
using namespace std;
int count_possible_tilings(int n)
{

    if (n<3) return n;
    int dp[n+1][3];
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;
    for (int i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-2][0]+dp[i-2][1]+dp[i-2][2];
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][2]=dp[i-1][0]+dp[i-1][1];
    }
    return dp[n][0];
}
int main(void)
{
    //dimesiion of rectangular grid is (2*n)
    int n=3;
    cout<<count_possible_tilings(n)<<endl;

}