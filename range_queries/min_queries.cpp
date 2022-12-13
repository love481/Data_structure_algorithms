#include<bits/stdc++.h>
using namespace std;
//Time complexity:O(nlongn)+m < naive (m*n^2) for large m such that k<=n
void minimum_range_queries(vector<int>&data,vector<vector<int>>&input_min_query)
{
    int sparse_table[data.size()][int(log2(data.size()))+1];
    for (int i=0;i<data.size();i++)sparse_table[i][0]=i;
    for (int j=1;(1<<j)<=data.size();j++)
    {
        for (int i=0;i+(1<<j)-1<data.size();i++) 
        {
            if (data[sparse_table[i][j-1]]<data[sparse_table[i+(1<<(j-1))][j-1]])
                sparse_table[i][j]=sparse_table[i][j-1];
            else
                sparse_table[i][j]=sparse_table[i+(1<<(j-1))][j-1];
        }
    }
    int x,y,k;
    for (int i=0;i<input_min_query.size();i++)
    {   
        x=input_min_query[i][0];
        y=input_min_query[i][1];
        k=(int)log2(y-x+1);
        cout<<x<<" "<<y<<" "<<min(data[sparse_table[x][k]],data[sparse_table[y-(1<<k)+1][k]])<<endl;

    }
}
int main(void)
{
    vector<int>data{-5,3,-1,7,8,0,9,6};
    vector<vector<int>>input_min_query{
        {0,4},
        {3,7},
        {1,5}
    };
    minimum_range_queries(data,input_min_query);


}