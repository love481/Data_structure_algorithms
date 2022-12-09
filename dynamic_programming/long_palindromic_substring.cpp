#include<bits/stdc++.h>
using namespace std;
int get_longest_substring(string str)
{
    int dp[str.length()+1][str.length()+1];
    memset(dp,0,sizeof dp);
    for(int i=0;i<str.length()+1;i++)dp[i][i]=1;
    for (int i=1;i<str.length()+1;i++){
        for (int j=0;j<str.length()+1-i;j++)
        {
            if (str[j] == str[j+i] && j==i)dp[j][j+i]=2;
            if (str[j] == str[j+i]) dp[j][j+i]=2+dp[j+1][j+i-1];
            else dp[j][j+i]=max(dp[j+1][j+i],dp[j][j+i-1]);
        }
    }
     for (int i=0;i<str.length()+1;i++){
        for (int j=0;j<str.length()+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][str.length()];
}
int main(void){

    string str="abcdcbe";
    cout<<get_longest_substring(str)<<endl;

}