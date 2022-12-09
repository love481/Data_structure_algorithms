#include<bits/stdc++.h>
using namespace std;
int find_longest_common_subsequence(vector<int>&a,vector<int>&b)
{
    int dp[a.size()+1][b.size()+1];
    memset(dp,0,sizeof dp);
    for (int i=1;i<a.size()+1;i++){
        for (int j=1;j<b.size()+1;j++)
        {
            if (a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[a.size()][b.size()];

}
int main(void){

    vector<int>a{1,4,6,2,4,8},b{2,4,3,13,9,8};
    cout<<find_longest_common_subsequence(a,b)<<endl;
}