#include<bits/stdc++.h>
using namespace std;
int find_min_edit_distance(string first_str,string second_str)
{
    int m=first_str.length(),n=second_str.length();
    int dp[m+1][n+1];
    for (int i=0;i<m+1;i++)
    {  
        for (int j=0;j<n+1;j++)
        {
            if (i==0)dp[0][j]=j;
            else if (j==0)dp[i][0]=i;
            else if(first_str[i-1]==second_str[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));

        }
    }
    return dp[m][n];

}
int main(void)
{
    string first_str="ten";
    string second_str="tent";
    cout<<find_min_edit_distance(first_str,second_str)<<endl;
}